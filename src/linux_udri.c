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
#include "la.h"
#include "la.c"

// TODO make this not garbage
const char *glx_read_file (const char *path) {
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


void *glx_alloc(usize size_bytes) {
  void *out = mmap(NULL, size_bytes,
                   PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON,
                   -1, 0);

  if (out == MAP_FAILED) {
    fprintf(stderr, "Could not allocate game memory: %s\n", strerror(errno));
    exit(1);
  }
  
  return out;
}

void glx_free(void *ptr, usize size_bytes) {
  if (ptr) {
    munmap(ptr, size_bytes);
  }
}

// TODO want to use memory arena of some kind and not just mmap every time i need like 3 bytes
GLuint glx_create_shader_program (const char *vs_path, const char *fs_path) {
  // Create the shaders
	GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

  // Read the shader code from the file
  const char *vertex_src = glx_read_file(vs_path);
  const char *fragment_src = glx_read_file(fs_path);

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
    char *error_msg = (char *) glx_alloc(error_msg_size_bytes);

    glGetShaderInfoLog(vertex_shader_id, info_log_length, NULL, error_msg);
    printf("%s: %s\n", vs_path, error_msg);
    glx_free((void *) error_msg, error_msg_size_bytes);
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
    char *error_msg = (char *) glx_alloc(error_msg_size_bytes);

    glGetShaderInfoLog(fragment_shader_id, info_log_length, NULL, error_msg);
    printf("%s: %s\n", fs_path, error_msg);
    glx_free((void *) error_msg, error_msg_size_bytes);
    exit(1);
  }

  // Link the program
  GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, vertex_shader_id);
	glAttachShader(ProgramID, fragment_shader_id);
	glLinkProgram(ProgramID);

  // Check the program
  glGetShaderiv(ProgramID, GL_LINK_STATUS, &result);
	glGetShaderiv(ProgramID, GL_INFO_LOG_LENGTH, &info_log_length);
  if (info_log_length > 0){
    usize error_msg_size_bytes = (info_log_length+1) * sizeof(char);
    char *error_msg = (char *) glx_alloc(error_msg_size_bytes);

    glGetShaderInfoLog(ProgramID, info_log_length, NULL, error_msg);
    printf("Could not create shader program: %s\n", error_msg);
    glx_free((void *) error_msg, error_msg_size_bytes);
    exit(1);
  }

  glDetachShader(ProgramID, vertex_shader_id);
	glDetachShader(ProgramID, fragment_shader_id);
	
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
  
	return ProgramID;
}

void gl_do_rendering(u32 width, u32 height, vec2 pos) {
  glViewport(0, 0, width, height);
      
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  const f32 a = 2.0f / (f32) width;
  const f32 b = 2.0f / (f32) height;
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

  f32 sprite_width = 150;
  f32 sprite_height = 300;
  
  vec2 min_p = {{
      (f32) width/2.0f  - sprite_width/2.0f,
      (f32) height/2.0f - sprite_height/2.0f
    }};
  
  vec2 max_p = {{
      min_p.x + sprite_width,
      min_p.y + sprite_height
    }};

  glBegin(GL_TRIANGLES);

  glColor4f(1,1,0,1); // Lower Triangle
      
  glTexCoord2f(0.0, 0.0);
  glVertex2fv(min_p.all);

  glTexCoord2f(1.0, 0.0);
  glVertex2f(max_p.x, min_p.y);

  glTexCoord2f(1.0, 1.0);
  glVertex2fv(max_p.all);

      
  glColor4f(1,0,0,1); // Upper Triangle

  glTexCoord2f(0.0, 0.0);
  glVertex2fv(min_p.all);

  glTexCoord2f(1.0, 1.0);
  glVertex2fv(max_p.all);

  glTexCoord2f(0.0, 1.0);
  glVertex2f(min_p.x, max_p.y);
      
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
                             DEFAULT_WIDTH, DEFAULT_HEIGHT,
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

  GLenum err = glewInit();
  if (err != GLEW_OK) {
    int major, minor;
    glXQueryVersion(display, &major, &minor);
    fprintf(stderr, "could not initialize glew: %s\n", glewGetErrorString(err));
    exit(1);
  }


  //GLuint program = glx_create_shader_program("./src/shaders/default.vs", "./src/shaders/default.fs");
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

  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC, &tp);
  f64 last_time = (f64) tp.tv_nsec / 1000000000.0;
  
  f64 dt = 0;
  vec2 pos = {0};
  vec2 vel = {0};
  vec2 acc = {0};
  bool should_quit = false; 
  while (!should_quit) {
    while (XPending(display) > 0) {
      XEvent event = {0};
      XNextEvent(display, &event);

      switch (event.type) {
      case KeyPress: {
        switch (XLookupKeysym((XKeyEvent *) &event, 0)) {
        case 'q': {
          should_quit = true;
        } break;
        }
      } break;
      }
    }

    clock_gettime(CLOCK_MONOTONIC, &tp);
    f64 current_time = (f64) tp.tv_nsec / 1000000000.0;
    dt = current_time - last_time;
    last_time = current_time;
    
    pos = vec2_add(vec2_mul_scalar(vel, dt),
                   vec2_mul_scalar(vec2_div_scalar(acc, 2),
                                   dt*dt));
    
    XWindowAttributes xwa;
    XGetWindowAttributes(display, win, &xwa);
    
    gl_do_rendering(xwa.width, xwa.height, pos);
    
    glXSwapBuffers(display, win);
  }

  glXMakeCurrent(display, None, NULL);
  glXDestroyContext(display, glc);
  XDestroyWindow(display, win);
  XCloseDisplay(display);
  return 0;
}
