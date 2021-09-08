#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>

#include <sys/mman.h>
#include <time.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include "linux_udri.h"

#ifndef UDRI_RELEASE
#define LADEF
#endif
#include "generated/udri_la.c"

//TODO write our own image loader
#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_JPEG
//#define STBI_NO_PNG
//#define STBI_NO_BMP
#define STBI_NO_PSD
#define STBI_NO_TGA
#define STBI_NO_GIF
#define STBI_NO_HDR
#define STBI_NO_PIC
#define STBI_NO_PNM
#include "../lib/stb_image.h"

// TODO make this not garbage
const char *linux_read_file (const char *path) {
  FILE *fd = fopen(path, "rb");
  if (!fd) {
    fprintf(stderr, "Could not open %s\n", path);
    exit(1);
  }

  fseek(fd, 0L, SEEK_END);
  i64 size = ftell(fd);
  rewind(fd);
  char *buffer = calloc(1, size+1);
  if (!buffer) {
    fprintf(stderr, "could not allocate memory for %s\n", path);
    fclose(fd);
    exit(1);
  }

  if(1!=fread(buffer , size, 1 , fd)) {
    fclose(fd);
    free(buffer);
    fprintf(stderr, "could not load contents of %s into memory\n", path);
    exit(1);
  }

  fclose(fd);
  
  return buffer;
}


void *linux_alloc(usize size_bytes) {
  void *out = mmap(NULL, size_bytes,
                   PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON,
                   -1, 0);

  if (out == MAP_FAILED) {
    fprintf(stderr, "Could not allocate game memory: %s\n", strerror(errno));
    exit(1);
  }
  
  return out;
}

void linux_free(void *ptr, usize size_bytes) {
  if (ptr) munmap(ptr, size_bytes);
}

// TODO want to use memory arena of some kind and not just mmap every time i need like 3 bytes
GLuint opengl_create_shader_program (const char *vs_path, const char *fs_path) {
  // Create the shaders
	GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

  // Read the shader code from the file
  const char *vertex_src = linux_read_file(vs_path);
  const char *fragment_src = linux_read_file(fs_path);

  GLint result = GL_FALSE;
	int info_log_length;
  
  // Compile Vertex Shader
  glShaderSource(vertex_shader_id, 1, &vertex_src , NULL);
  glCompileShader(vertex_shader_id);

  // Check Vertex Shader
  glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0){
    usize error_msg_size_bytes = (info_log_length+1) * sizeof(char);
    char *error_msg = (char *) linux_alloc(error_msg_size_bytes);

    glGetShaderInfoLog(vertex_shader_id, info_log_length, NULL, error_msg);
    printf("%s: %s\n", vs_path, error_msg);
    linux_free((void *) error_msg, error_msg_size_bytes);
    exit(1);
  }

  // Compile Fragment Shader
  glShaderSource(fragment_shader_id, 1, &fragment_src , NULL);
  glCompileShader(fragment_shader_id);

  // Check Fragment Shader
  glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0){
    usize error_msg_size_bytes = (info_log_length+1) * sizeof(char);
    char *error_msg = (char *) linux_alloc(error_msg_size_bytes);

    glGetShaderInfoLog(fragment_shader_id, info_log_length, NULL, error_msg);
    printf("%s: %s\n", fs_path, error_msg);
    linux_free((void *) error_msg, error_msg_size_bytes);
    exit(1);
  }

  // Link the program
  GLuint program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);
	glLinkProgram(program_id);

  // Check the program
  glGetShaderiv(program_id, GL_LINK_STATUS, &result);
	glGetShaderiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0){
    usize error_msg_size_bytes = (info_log_length+1) * sizeof(char);
    char *error_msg = (char *) linux_alloc(error_msg_size_bytes);

    glGetShaderInfoLog(program_id, info_log_length, NULL, error_msg);
    printf("Could not create shader program: %s\n", error_msg);
    linux_free((void *) error_msg, error_msg_size_bytes);
    exit(1);
  }

  glDetachShader(program_id, vertex_shader_id);
	glDetachShader(program_id, fragment_shader_id);
	
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
  
	return program_id;
}

void gl_render_sprite(u32 sprite_target_width, u32 sprite_target_height,
                      vec2 pos, const u8 *sprite,
                      u32 sprite_width, u32 sprite_height,
                      GLuint texture_handle, bool flip_x) {
  
  glBindTexture(GL_TEXTURE_2D, texture_handle);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, sprite_width, sprite_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, sprite);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
  glEnable(GL_TEXTURE_2D);
  
  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  const f32 a = 2.0f / (f32) ASPECT_WIDTH;
  const f32 b = 2.0f / (f32) ASPECT_HEIGHT;
  f32 proj[] = {
     a,  0,  0,  0,
     0,  b,  0,  0,
     0,  0,  1,  0,
    -1, -1,  0,  1,
  };
  glLoadMatrixf(proj);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(pos.x, pos.y, 0);
  
  vec2 min_p = {{
      (f32) ASPECT_WIDTH/2.0f  - (f32) sprite_target_width/2.0f,
      (f32) ASPECT_HEIGHT/2.0f - (f32) sprite_target_height/2.0f,
    }};
  
  vec2 max_p = {{
      min_p.x + sprite_target_width,
      min_p.y + sprite_target_height
    }};
  
  glBegin(GL_TRIANGLES);

  glEnable(GL_BLEND);// you enable blending function
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDepthMask(GL_TRUE);

  const f32
    tex_min_x = flip_x ? 1.0 : 0.0,
    tex_max_x = flip_x ? 0.0 : 1.0;

  

  //glColor4f(0.0, 0.0, 0.0, 0.0);
  
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
  glDisable(GL_BLEND);
  glEnd();
}

int main (int argc, char **argv) {
  (void) argc;
  (void) argv;

  Display *display = XOpenDisplay(NULL);
  if (display == NULL) {
    fprintf(stderr, "cannot connect to X server: %s\n", strerror(errno));
    return 1;
  }

  Window root = XDefaultRootWindow(display);
  
  GLint attrib[] = {
    GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None
  };
  XVisualInfo *visual = glXChooseVisual(display, 0, attrib);
  if (visual == NULL) {
    fprintf(stderr, "no visual found: %s\n", strerror(errno));
    return 1;
  }

  Colormap cmap = XCreateColormap(display, root, visual->visual, AllocNone);

  XSetWindowAttributes swa;
  swa.colormap   = cmap;
  swa.event_mask =
    ExposureMask | KeyPressMask | StructureNotifyMask | KeyReleaseMask;

  Window win = XCreateWindow(display, root,
                             0, 0,
                             1, 1, // TODO detect screen resolution
                             0,
                             visual->depth,
                             InputOutput,
                             visual->visual,
                             CWColormap | CWEventMask, &swa);

  GLXContext glc = glXCreateContext(display, visual, NULL, GL_TRUE);

  XFree(visual);

  XMapWindow(display, win);
  XStoreName(display, win, WINDOW_NAME);
  glXMakeCurrent(display, win, glc);
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_GREATER, 0.0f);
  
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    fprintf(stderr, "could not initialize glew: %s\n",
            glewGetErrorString(err));
    exit(1);
  }
  
  //GLuint program = opengl_create_shader_program("./src/shaders/default.vs", "./src/shaders/default.fs");
  /*
  const GLfloat vertices[] = {
    -0.5, -0.5, 0.0, 1.0, // first triangle
    -0.5, +0.5, 0.0, 1.0,
    +0.5, +0.5, 0.0, 1.0,
    +0.5, +0.5, 0.0, 1.0, // second triangle
    +0.5, -0.5, 0.0, 1.0,
    -0.5, -0.5, 0.0, 1.0,
	};

  GLuint vertex_buffer;
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  */

  // initialize game memory stuff
  /*
  LinuxVertexBuffer vertex_buffer;
  vertex_buffer.size_bytes = 0;
  vertex_buffer.current = 0;
  vertex_buffer.num_vertices = 0;
  vertex_buffer.max_vertices = 0;
  */

  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC, &tp);
  u64 last_time = (u64) tp.tv_nsec;


  // TODO unhardcode this stuff
  //player
  int sprite_width, sprite_height, channels;
  const u8 *player_sprite = stbi_load("./res/guy.bmp", &sprite_width, &sprite_height, &channels, STBI_rgb_alpha);
  if (!player_sprite) {
    fprintf(stderr, "could not load sprite: %s\n", strerror(errno));
    exit(1);
  }
  GLuint player_sprite_gl_handle = 0;
  glGenTextures(1, &player_sprite_gl_handle);

  //background
  int bg_sprite_width, bg_sprite_height, bg_channels;
  const u8 *bg_sprite = stbi_load("./res/bg.bmp", &bg_sprite_width, &bg_sprite_height, &bg_channels, STBI_rgb_alpha);
  if (!bg_sprite) {
    fprintf(stderr, "could not load sprite: %s\n", strerror(errno));
    exit(1);
  }
  GLuint bg_sprite_gl_handle = 1;
  glGenTextures(1, &bg_sprite_gl_handle);
  
  const f32
    player_speed  = 5,
    player_width  = 1,
    player_height = 2,
    jump_height   = 1,
    jump_duration = 0.25,
    jump_vel      = (2.0 * jump_height) / jump_duration,
    jump_gravity  = (-2.0 * jump_height) / (jump_duration * jump_duration);
  
  const vec2 acc = make_vec2(0, jump_gravity);
  const u32 num_jumps = 3;
  const u32 num_dashes = 1;
  
  u64
    screen_width    = 0,
    screen_height   = 0,
    screen_x_origin = 0,
    screen_y_origin = 0;
  
  f32 dt = 0;
  vec2 pos = {0};
  vec2 vel = {0};
  u32 jumps = num_jumps;
  u32 dashes = num_dashes;
  bool should_quit = false;
  bool turned_left = false;
  while (!should_quit) {
    while (XPending(display) > 0) {
      XEvent event = {0};
      XNextEvent(display, &event);

      switch (event.type) {
      case KeyPress: {
        switch (keybinds[event.xkey.keycode]) {
        case UDRI_BUTTON_START: {
          should_quit = true;
        } break;

        case UDRI_BUTTON_UP: {
          if (jumps) {
            vel.y = jump_vel;
            jumps--;
          }
        } break;

        case UDRI_BUTTON_LEFT: {
          turned_left = true;
          vel.x = -player_speed;
        } break;

        case UDRI_BUTTON_RIGHT: {
          turned_left = false;
          vel.x = player_speed;
        } break;

        case UDRI_BUTTON_DOWN: {
          vel.y = -jump_vel;
          jumps = 0;
        } break;

        case UDRI_BUTTON_L: {
          if (dashes) {
            vel = vec2_mul_scalar(vel, 2);
            dashes--;
          }
        } break;

        default: {
          //printf("%d\n", event.xkey.keycode);
        } break;
          
        }
      } break;
        
      case KeyRelease: {
        switch (keybinds[event.xkey.keycode]) {
        case UDRI_BUTTON_LEFT: {
          if (vel.x < 0) vel.x = 0;
        } break;
          
        case UDRI_BUTTON_RIGHT: {
          if (vel.x > 0) vel.x = 0;
        } break;
      } break;
      }

      case ConfigureNotify: {
        const usize
          old_w = screen_width,
          new_w = event.xconfigure.width,
          new_h = event.xconfigure.height;

        if (new_w != old_w) {
          screen_width = new_w;
          screen_height = new_w / ASPECT_RATIO;
          screen_x_origin = 0;
          screen_y_origin = (i64) (((f64) new_h - (f64) screen_height) * 0.5);
          if (screen_height > new_h) {
            screen_height = new_h;
            screen_width = new_h * ASPECT_RATIO;
            screen_y_origin = 0;
            screen_x_origin = (i64) (((f64) new_w - (f64) screen_width) * 0.5);
          }
        }
      } break;
      }
    }

    clock_gettime(CLOCK_MONOTONIC, &tp);
    u64 current_time = (u64) tp.tv_nsec;
    //TODO figure out why clock_gettime fucks up sometimes
    if (current_time > last_time)
      dt = (f32) (current_time - last_time) / 1000000000.0;
    last_time = current_time;
    
    // platform indepentent stuff
    {
      // update
      const vec2 new_pos = vec2_add(pos, vec2_add(vec2_mul_scalar(vel, dt), vec2_mul_scalar(acc, 0.5*dt*dt)));
      vel = vec2_add(vel, vec2_mul_scalar(acc, dt));

      // TODO actual collision detection
      const f32 bottom = (-ASPECT_HEIGHT + player_height) * 0.5;
      if (new_pos.y < bottom) {
        vel.y = 0;
        pos.y = bottom;
        pos.x = new_pos.x;
        jumps = num_jumps;
        dashes = num_dashes;
      } else pos = new_pos;

      // render
      glClearColor(0.5, 0.5, 0.5, 1.0);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glScissor(screen_x_origin, screen_y_origin, screen_width, screen_height);
      glEnable(GL_SCISSOR_TEST);
      glClearColor(0.0, 0.0, 0.0, 0.0);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glDisable(GL_SCISSOR_TEST);
    
      glViewport(screen_x_origin, screen_y_origin, screen_width, screen_height);
      gl_render_sprite(player_width, player_height, pos, player_sprite, sprite_width, sprite_height, player_sprite_gl_handle, turned_left);
      const vec2 bg_pos = make_vec2_scalar(0.0f);
      gl_render_sprite(ASPECT_WIDTH, ASPECT_HEIGHT, bg_pos, bg_sprite, bg_sprite_width, bg_sprite_height, bg_sprite_gl_handle, false);
    }
    
    glXSwapBuffers(display, win);
  }

  glXMakeCurrent(display, None, NULL);
  glXDestroyContext(display, glc);
  XDestroyWindow(display, win);
  XCloseDisplay(display);
  return 0;
}
