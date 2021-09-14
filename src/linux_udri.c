#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/mman.h>
#include <time.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

#include "udri.c"
#include "linux_udri.h"

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

int main (void) {
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
  
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    fprintf(stderr, "could not initialize glew: %s\n",
            glewGetErrorString(err));
    exit(1);
  }
  
  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC, &tp);
  u64 last_time = (u64) tp.tv_nsec;
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_GREATER, 0.0f);

  GameState state = {0};
  GameInput input = {0};
  
  while (!state.should_quit) {
    input.released = UDRI_BUTTON_NONE;
    input.pressed  = UDRI_BUTTON_NONE;
    
    while (XPending(display) > 0) {
      XEvent event = {0};
      XNextEvent(display, &event);
      
      switch (event.type) {
      case KeyPress: {
        const button_mask btn = linux_keybinds[event.xkey.keycode];

        // NOTE because keys that aren't mapped return multiple set bits
        if(HAS_ONLY_ONE_SET_BIT(btn)) {
          input.pressed  |= btn;
          input.held     |= btn;
          input.released &= ~btn;
        }
      } break;
        
      case KeyRelease: {
        const button_mask btn = linux_keybinds[event.xkey.keycode];

        if(HAS_ONLY_ONE_SET_BIT(btn)) {
          input.released |= btn;
          input.pressed  &= ~btn;
          input.held     &= ~btn;
        }
      } break;

      case ConfigureNotify: {
        const u64
          old_w = state.screen.width,
          old_h = state.screen.height,
          new_w = event.xconfigure.width,
          new_h = event.xconfigure.height;

        const f64 new_aspect_ratio = (f32) new_w / (f32) new_h;

        if (new_w != old_w || new_h != old_h) {
          if (new_aspect_ratio == ASPECT_RATIO) {
            state.screen.width    = new_w;
            state.screen.height   = new_h;
            state.screen.x_origin = 0;
            state.screen.y_origin = 0;
          } else if (new_aspect_ratio < ASPECT_RATIO) {
            state.screen.width    = new_w;
            state.screen.height   = new_w / ASPECT_RATIO;
            state.screen.x_origin = 0;
            state.screen.y_origin = (i64) (((f64) new_h - (f64) state.screen.height) * 0.5);
          } else if (new_aspect_ratio > ASPECT_RATIO) {
            state.screen.width    = new_h * ASPECT_RATIO;
            state.screen.height   = new_h;
            state.screen.x_origin = (i64) (((f64) new_w - (f64) state.screen.width) * 0.5);
            state.screen.y_origin = 0;
          }

          //printf("%f - %f\n", new_aspect_ratio, ASPECT_RATIO);
        }
      } break;
      }
    }

    clock_gettime(CLOCK_MONOTONIC, &tp);
    u64 current_time = (u64) tp.tv_nsec;
    //TODO figure out why clock_gettime fucks up sometimes
    //NOTE fps seems to be locked to 60 which is good but i have no idea why
    if (current_time > last_time)
      state.dt = (f32) (current_time - last_time) / 1000000000.0f;
    //printf("%f\n", dt);
    last_time = current_time;

    //printf("%f\n", state.dt);
    
    game_update_and_render(&state, &input);
    
    glXSwapBuffers(display, win);
  }

  glXMakeCurrent(display, None, NULL);
  glXDestroyContext(display, glc);
  XDestroyWindow(display, win);
  XCloseDisplay(display);
  return 0;
}
