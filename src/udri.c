#include "udri.h"
#include "GL/gl.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "../lib/stb_image.h"

// TODO write our own bmp loader and maybe don't do the gl stuff idk
void DEBUG_load_bitmap(Bitmap *bmp, const char *path) {
  
  bmp->data = stbi_load(path, (i32 *) &bmp->width, (i32 *) &bmp->height,
                             NULL, STBI_rgb_alpha);
  if (!bmp->data) {
    fprintf(stderr, "could not load sprite: %s\n", strerror(errno));
    exit(1);
  }
}

void assert(bool b) {
  if (!b) {
    printf("ASSERTION FAILED\n");
    byte dead = *((byte *) NULL);
    (void) dead;
  }
}

// TODO clean this up, also eventually use vbo to render all bmps at once instead of the stupid fli_x and translatef stuff
void gl_render_bitmap(RenderTarget rt, vec2 position, bool flip_x) {
  assert(rt.current_frame_idx < rt.num_frames);
  glBindTexture(GL_TEXTURE_2D, rt.gl_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
               rt.frames[rt.current_frame_idx].width,
               rt.frames[rt.current_frame_idx].height,
               0, GL_RGBA, GL_UNSIGNED_BYTE,
               rt.frames[rt.current_frame_idx].data);
  
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

void game_update_and_render(GameState *state, GameInput *input) {
  if (!state->is_initialized) {
    state->is_initialized = true;
    
    state->player.pos         = v2_scalar(0.0f);
    state->player.vel         = v2_scalar(0.0f);
    state->player.jumps       = PLAYER_NUM_JUMPS;
    state->player.dashes      = PLAYER_NUM_DASHES;
    state->player.turned_left = false;

    const usize frames_played_for = 15;
    DEBUG_load_bitmap(&state->player.render.frames[0],
                      "./res/falcon/idle0.bmp");
    state->player.render.frames[0].frames_played_for = frames_played_for;
    DEBUG_load_bitmap(&state->player.render.frames[1],
                      "./res/falcon/idle1.bmp");
    state->player.render.frames[1].frames_played_for = frames_played_for;
    DEBUG_load_bitmap(&state->player.render.frames[2],
                      "./res/falcon/idle2.bmp");
    state->player.render.frames[2].frames_played_for = frames_played_for;
    DEBUG_load_bitmap(&state->player.render.frames[3],
                      "./res/falcon/idle3.bmp");
    state->player.render.frames[3].frames_played_for = frames_played_for;
    state->player.render.num_frames = 4;
    state->player.render.width  = PLAYER_WIDTH;
    state->player.render.height = PLAYER_HEIGHT;
    state->player.render.layer  = RENDER_TARGET_PLAYER_LAYER;
  
    glGenTextures(1, &state->player.render.gl_id);

    DEBUG_load_bitmap(&state->background_render.frames[0], "./res/bg.bmp");
    state->background_render.num_frames = 1;
    state->background_render.width  = ASPECT_WIDTH;
    state->background_render.height = ASPECT_HEIGHT;
    state->background_render.layer  = RENDER_TARGET_BACKGROUND_LAYER;
    glGenTextures(1, &state->background_render.gl_id);

    Bitmap orb_bmp;
    DEBUG_load_bitmap(&orb_bmp, "./res/orb.bmp");
    u32 orb_gl_id;
    glGenTextures(1, &orb_gl_id);
    for (usize i = 0; i < NUM_ORBS; ++i) {
      state->orbs[i].render.frames[0]  = orb_bmp;
      state->orbs[i].render.num_frames = 1;
      state->orbs[i].render.width      = ORB_WIDTH;
      state->orbs[i].render.height     = ORB_HEIGHT;
      state->orbs[i].render.layer      = RENDER_TARGET_ORB_LAYER;
      state->orbs[i].render.gl_id      = orb_gl_id;
    
      const i32
        upper_x = (i32) (ASPECT_WIDTH / 2.0),
        lower_x = -upper_x,
        upper_y = (i32) (ASPECT_HEIGHT / 2.0),
        lower_y = -upper_y;
    
      state->orbs[i].pos.x = (rand() % (upper_x - lower_x + 1)) + lower_x;
      state->orbs[i].pos.y = (rand() % (upper_y - lower_y + 1)) + lower_y;
    }
  }
  
  // proccess input
  if (input->pressed & UDRI_BUTTON_START)
    state->should_quit = true;
      
  if (input->pressed & UDRI_BUTTON_X) {
    if (state->player.jumps) {
      state->player.vel.y = PLAYER_JUMP_VELOCITY;
      state->player.jumps--;
    }
  }

  if (input->pressed & UDRI_BUTTON_LEFT) {
    state->player.turned_left = true;
    state->player.vel.x = -PLAYER_SPEED;
  }

  if (input->pressed & UDRI_BUTTON_RIGHT) {
    state->player.turned_left = false;
    state->player.vel.x = PLAYER_SPEED;
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
    if (state->player.vel.x < 0) state->player.vel.x = 0;
  }
      
  if (input->released & UDRI_BUTTON_RIGHT) {
    if (state->player.vel.x > 0) state->player.vel.x = 0;
  }
      
  // update
  {
    RenderTarget *r = &state->player.render;
    r->frames_elapsed++;
    //printf("%lu\n", r->frames_elapsed);
    if (r->frames_elapsed >= r->frames[r->current_frame_idx].frames_played_for) {
      //printf("NEW FRAME\n");
      r->current_frame_idx += (r->current_frame_idx < r->num_frames-1) ?
        1 : (-r->current_frame_idx);
      r->frames_elapsed = 0;
      //printf("%lu\n", r->current_frame_idx);
    }
  }
  
  const f32 player_new_y =
    state->player.pos.y + ((state->player.vel.y*state->dt) + (PLAYER_JUMP_GRAVITY*0.5*state->dt*state->dt));
  state->player.pos.x += state->player.vel.x * state->dt;
  state->player.vel.y += PLAYER_JUMP_GRAVITY * state->dt;

  // TODO actual collision detection
  const f32 bottom = (PLAYER_HEIGHT - ASPECT_HEIGHT) * 0.5;
  if (player_new_y < bottom) {
    state->player.vel.y  = 0;
    state->player.pos.y  = bottom;
    state->player.jumps  = PLAYER_NUM_JUMPS;
    state->player.dashes = PLAYER_NUM_DASHES;
        
    // probably don't want to do this but we'll see its funny
    if (input->held & UDRI_BUTTON_X) {
      if (state->player.jumps) {
        state->player.vel.y = PLAYER_JUMP_VELOCITY;
        state->player.jumps--;
      }
    }
  } else state->player.pos.y = player_new_y;
      
  // render
  const vec4 border_color = v4(0.0f, 0.0f, 0.0f, 1.0);
  glClearColor(border_color.r, border_color.g, border_color.b, border_color.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(state->screen.x_origin, state->screen.y_origin, state->screen.width, state->screen.height);

  // TODO add a vX_zero and maybe vX_unit
  gl_render_bitmap(state->background_render, v2_scalar(0.0f), false);
  gl_render_bitmap(state->player.render, state->player.pos, state->player.turned_left);
      
  for (usize i = 0; i < NUM_ORBS; ++i)
    gl_render_bitmap(state->orbs[i].render, state->orbs[i].pos, false);
}
