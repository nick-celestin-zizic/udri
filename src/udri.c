#include "udri.h"
#include "generated/udri_la.h"

#include "GL/gl.h"

//TODO write our own image loader
#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_JPEG
#define STBI_NO_PNG
//#define STBI_NO_BMP
#define STBI_NO_PSD
#define STBI_NO_TGA
#define STBI_NO_GIF
#define STBI_NO_HDR
#define STBI_NO_PIC
#define STBI_NO_PNM
#define STBI_ASSERT(x) ((void)(x))
#include "../lib/stb_image.h"

// TODO write our own bmp loader
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
void
DEBUG_load_bitmap(Bitmap *bmp, const char *path) {
  
  bmp->data = stbi_load(path, (i32 *) &bmp->width, (i32 *) &bmp->height,
                             NULL, STBI_rgb_alpha);
  if (!bmp->data) {
    fprintf(stderr, "could not load sprite: %s\n", strerror(errno));
    exit(1);
  }
}

void
assert(bool b) {
  if (!b) {
    printf("ASSERTION FAILED\n");
    byte dead = *((byte *) NULL);
    (void) dead;
  }
}

// TODO clean this up, also eventually use vbo to render all bmps at once instead of the stupid fli_x and translatef stuff
void
gl_render_bitmap(RenderTarget rt, vec2 position, bool flip_x) {
  assert(rt.current_bmp_idx < rt.num_bmps);
  glBindTexture(GL_TEXTURE_2D, rt.gl_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
               rt.bmps[rt.current_bmp_idx].width,
               rt.bmps[rt.current_bmp_idx].height,
               0, GL_RGBA, GL_UNSIGNED_BYTE,
               rt.bmps[rt.current_bmp_idx].data);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
  glEnable(GL_TEXTURE_2D);
  
  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  const f32 a = 2.0f / ASPECT_WIDTH;
  const f32 b = 2.0f / ASPECT_HEIGHT;
  f32 proj[] = {
     a,  0,  0,  0,
     0,  b,  0,  0,
     0,  0,  1,  0,
    -1, -1,  0,  1,
  };
  glLoadMatrixf(proj);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(position.x, position.y, rt.layer);
  
  const vec2
    min_p = v2(ASPECT_WIDTH/2.0f  - rt.width/2.0f,
               ASPECT_HEIGHT/2.0f - rt.height/2.0f),
    max_p = v2(min_p.x + rt.width,
               min_p.y + rt.height);

  const f32
    tex_min_x = flip_x ? 1.0 : 0.0,
    tex_max_x = flip_x ? 0.0 : 1.0;
  
  glBegin(GL_TRIANGLES);
  
  glTexCoord2f(tex_min_x, 1.0);
  glVertex2fv(min_p.all);
  
  glTexCoord2f(tex_max_x, 1.0);
  glVertex2f(max_p.x, min_p.y);
  
  glTexCoord2f(tex_max_x, 0.0);
  glVertex2fv(max_p.all);

  
  glTexCoord2f(tex_min_x, 1.0);
  glVertex2fv(min_p.all);
  
  glTexCoord2f(tex_max_x, 0.0);
  glVertex2fv(max_p.all);
  
  glTexCoord2f(tex_min_x, 0.0);
  glVertex2f(min_p.x, max_p.y);
  
  glEnd();
}

static void
udri_load_animation_frames(RenderTarget *r) {
  for (usize idx = 0; idx < r->num_bmps; idx++) {
    const usize max_size = 256;
    char path[max_size];
    snprintf(path, max_size, "./res/%s%03lu.bmp", r->name, idx);
    DEBUG_load_bitmap(&r->bmps[idx], path);
  }
}

static void
loop_animation(RenderTarget *r) {
  r->frames_elapsed++;
  const usize max_frame_time =
    r->frame_times[r->current_bmp_idx % r->num_unique_frame_times];
  if (r->frames_elapsed >= max_frame_time) {
    r->current_bmp_idx += (r->current_bmp_idx < r->num_bmps-1) ?
      1 : (-r->current_bmp_idx);
    r->frames_elapsed = 0;
  }
}

static void
advance_animation(RenderTarget *r) {
  const usize max_frames =
    r->frame_times[r->current_bmp_idx % r->num_unique_frame_times];
  if (r->frames_elapsed < max_frames) {
    r->frames_elapsed++;
  } else if (r->current_bmp_idx < r->num_bmps-1) {
      r->current_bmp_idx++;
      r->frames_elapsed = 0;
  }
}

static inline void
reset_animation(RenderTarget *r) {
  r->current_bmp_idx = 0;
  r->frames_elapsed  = 0;
}

static inline usize
current_frame_time(RenderTarget *r) {
  return r->frame_times[r->current_bmp_idx % r->num_unique_frame_times];
}

static inline bool
animation_is_finished(RenderTarget *r) {
  return (r->current_bmp_idx == r->num_bmps-1 &&
          r->frames_elapsed  == current_frame_time(r));
}

void
game_update_and_render(GameState *state, GameInput *input) {
  if (!state->is_initialized) {
    state->is_initialized = true;

    
    state->player.jumps       = PLAYER_NUM_JUMPS;
    state->player.dashes      = PLAYER_NUM_DASHES;
    
    for (usize player_state = 0;
         player_state < PLAYER_STATE_COUNT;
         player_state++) {
      state->player.renders[player_state] = player_renders[player_state];
      udri_load_animation_frames(&state->player.renders[player_state]);
      glGenTextures(1, &state->player.renders[player_state].gl_id);
    }
    
    {
      RenderTarget *r = &state->background_render;
      // TODO render background in multiple layers for parallax
      DEBUG_load_bitmap(&r->bmps[0], "./res/bg.bmp");
      r->num_bmps = 1;
      r->width  = ASPECT_WIDTH;
      r->height = ASPECT_HEIGHT;
      r->layer  = RENDER_TARGET_BACKGROUND_LAYER;
      glGenTextures(1, &r->gl_id);
    }

    {
      RenderTarget *r = &state->orbs.render;
      r->name                   = "orb/idle";
      r->num_bmps               = 6;
      r->num_unique_frame_times = 1;
      r->frame_times[0]         = 6;
      r->width                  = ORB_WIDTH;
      r->height                 = ORB_HEIGHT;
      r->layer                  = RENDER_TARGET_ORB_LAYER;
      udri_load_animation_frames(r);
      glGenTextures(1, &r->gl_id);
    }
    
    for (usize i = 0; i < NUM_ORBS; ++i) {
      const i32
        upper_x = (i32) (ASPECT_WIDTH / 2.0),
        lower_x = -upper_x,
        upper_y = (i32) (ASPECT_HEIGHT / 2.0),
        lower_y = -upper_y;
    
      state->orbs.pos[i].x = (rand() % (upper_x - lower_x + 1)) + lower_x;
      state->orbs.pos[i].y = (rand() % (upper_y - lower_y + 1)) + lower_y;
    }
  }
    // update
  const f32 player_new_y =
    state->player.pos.y + ((state->player.vel.y*state->dt) + (PLAYER_JUMP_GRAVITY*0.5*state->dt*state->dt));
  state->player.pos.x += state->player.vel.x * state->dt;
  state->player.vel.y += PLAYER_JUMP_GRAVITY * state->dt;

  // TODO actual collision detection and don't use render coordinates
  const f32 bottom =
    (state->player.renders[state->player.render_state].height - ASPECT_HEIGHT) * 0.5;
  if (player_new_y < bottom) {
    state->player.vel.y  = 0;
    state->player.pos.y  = bottom;
    state->player.jumps  = PLAYER_NUM_JUMPS;
    state->player.dashes = PLAYER_NUM_DASHES;
    
    if (state->player.is_grounded)
      state->player.was_grounded = true;
    else
      state->player.is_grounded = true;
        
    // probably don't want to do this but we'll see its funny
    if (input->held & UDRI_BUTTON_X) {
      if (state->player.jumps) {
        state->player.vel.y = PLAYER_JUMP_VELOCITY;
        state->player.jumps--;
      }
    }
  } else {
    state->player.pos.y = player_new_y;
    if (!state->player.is_grounded)
      state->player.was_grounded = false;
    else
      state->player.is_grounded = false;
  }
  
  // proccess input
  if (input->pressed & UDRI_BUTTON_START)
    state->should_quit = true;
      
  if (input->pressed & UDRI_BUTTON_X) {
    if (state->player.is_grounded) {
      state->player.is_grounded = false;
    } else if (state->player.was_grounded){
      state->player.was_grounded = false;
    } else if (state->player.jumps) {
      state->player.vel.y = PLAYER_JUMP_VELOCITY;
      state->player.jumps--;
    }
  }

  if (!state->player.is_landing || !state->player.is_grounded) {
    if (input->held & UDRI_BUTTON_LEFT) {
      state->player.turned_left = true;
      state->player.vel.x = -PLAYER_SPEED;
    }
    
    if (input->held & UDRI_BUTTON_RIGHT) {
      state->player.turned_left = false;
      state->player.vel.x = PLAYER_SPEED;
    }
  } else {
    state->player.vel.x = 0.0f;
  }

  if (input->pressed & UDRI_BUTTON_DOWN) {
    state->player.vel.y = -PLAYER_JUMP_VELOCITY;
    state->player.jumps = 0;
  }

  if (input->pressed & UDRI_BUTTON_L) {
    if (state->player.dashes) {
      state->player.vel = vec2_mul_scalar(state->player.vel, 2);
      state->player.dashes--;
    }
  }
      
  if (input->released & UDRI_BUTTON_LEFT) {
    //state->player.vel.x += PLAYER_SPEED;
    if (state->player.vel.x < 0) state->player.vel.x = 0;
  }
      
  if (input->released & UDRI_BUTTON_RIGHT) {
    //state->player.vel.x -= PLAYER_SPEED;
    if (state->player.vel.x > 0) state->player.vel.x = 0;
  }
      

  // render
  if (state->player.is_grounded) {
    reset_animation(&state->player.renders[PLAYER_STATE_JUMPING]);
    if (state->player.was_grounded) {
      if (animation_is_finished(&state->player.renders[PLAYER_STATE_LANDING])) {
        reset_animation(&state->player.renders[PLAYER_STATE_LANDING]);
        state->player.is_landing = false;
      }

      if (!state->player.is_landing) {
        state->player.render_state = (state->player.vel.x == 0) ?
        PLAYER_STATE_IDLE : PLAYER_STATE_RUNNING;
      }
    } else {
      state->player.is_landing = true;
      state->player.render_state = PLAYER_STATE_LANDING;
    }
  } else {
    reset_animation(&state->player.renders[PLAYER_STATE_LANDING]);
    state->player.render_state = PLAYER_STATE_JUMPING;
  }
  
  if (state->player.renders[state->player.render_state].looped)
    loop_animation(&state->player.renders[state->player.render_state]);
  else
    advance_animation(&state->player.renders[state->player.render_state]);
  
  loop_animation(&state->orbs.render);
  
  const vec4 border_color = v4(0.0f, 0.0f, 0.0f, 1.0);
  glClearColor(border_color.r, border_color.g, border_color.b, border_color.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(state->screen.x_origin, state->screen.y_origin, state->screen.width, state->screen.height);

  // TODO add a vX_zero and maybe vX_unit
  gl_render_bitmap(state->background_render, v2_scalar(0.0f), false);
  
  gl_render_bitmap(state->player.renders[state->player.render_state], state->player.pos, state->player.turned_left);
      
  for (usize i = 0; i < NUM_ORBS; ++i)
    gl_render_bitmap(state->orbs.render, state->orbs.pos[i], false);
}
