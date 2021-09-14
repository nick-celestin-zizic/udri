#ifndef _UDRI_H
#define _UDRI_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "./generated/udri_la.h"

typedef unsigned char byte;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef size_t usize;

typedef float  f32;
typedef double f64;

#define WINDOW_NAME "udri"
#define ASPECT_WIDTH 16.0f
#define ASPECT_HEIGHT 9.0f
#define ASPECT_RATIO (ASPECT_WIDTH / ASPECT_HEIGHT)

typedef u16 button_mask;
#define UDRI_BUTTON_START   0x0001
#define UDRI_BUTTON_A       0x0002
#define UDRI_BUTTON_B       0x0004
#define UDRI_BUTTON_X       0x0008
#define UDRI_BUTTON_Z       0x0010
#define UDRI_BUTTON_L       0x0020
#define UDRI_BUTTON_UP      0x0040
#define UDRI_BUTTON_LEFT    0x0080
#define UDRI_BUTTON_DOWN    0x0100
#define UDRI_BUTTON_RIGHT   0x0200
#define UDRI_BUTTON_MOD_X   0x0400
#define UDRI_BUTTON_MOD_Y   0x0800
#define UDRI_BUTTON_C_RIGHT 0x1000
#define UDRI_BUTTON_C_UP    0x2000
#define UDRI_BUTTON_C_LEFT  0x4000
#define UDRI_BUTTON_C_DOWN  0x8000
#define UDRI_BUTTON_NONE    0x0000
#define UDRI_BUTTON_ALL     0xffff

#define HAS_ONLY_ONE_SET_BIT(b) (b && !(btn & (btn - 1)))

typedef struct {
  button_mask held;
  button_mask pressed;
  button_mask released;
} GameInput;

typedef struct {
  const u8 *data;
  u32 width, height;
  usize frames_played_for;
} Bitmap;

#define RENDER_TARGET_MAX_FRAMES        100
#define RENDER_TARGET_BACKGROUND_LAYER  0.9f
#define RENDER_TARGET_PLAYER_LAYER      0.1f
#define RENDER_TARGET_ORB_LAYER         0.8f
typedef struct {
  usize num_frames;
  usize current_frame_idx;
  usize frames_elapsed;
  Bitmap frames[RENDER_TARGET_MAX_FRAMES];
  f32 width, height;
  f32 layer;
  u32 gl_id;
} RenderTarget; // TODO think of a better name and maybe reduntant

// NOTE temporary
#define NUM_ORBS   10
#define ORB_WIDTH  0.5f
#define ORB_HEIGHT 0.5f
typedef struct {
  vec2 pos[NUM_ORBS];
  RenderTarget render;
} Orbs;

// TODO have some sort of hotloaded file or smthn
typedef enum {
  PLAYER_STATE_IDLE = 0,
  PLAYER_STATE_RUNNING,
  PLAYER_STATE_JUMPING,
  //PLAYER_STATE_
} PlayerState;

#define PLAYER_WIDTH          1.0f
#define PLAYER_HEIGHT         1.5f
#define PLAYER_SPEED          5.0f
#define PLAYER_JUMP_HEIGHT    1.0f
#define PLAYER_NUM_DASHES     1.0f
#define PLAYER_NUM_JUMPS      3.0f
#define PLAYER_JUMP_DURATION  0.25f
#define PLAYER_JUMP_VELOCITY ((2.0*PLAYER_JUMP_HEIGHT)/PLAYER_JUMP_DURATION)
#define PLAYER_JUMP_GRAVITY  ((-2.0*PLAYER_JUMP_HEIGHT)/(PLAYER_JUMP_DURATION*PLAYER_JUMP_DURATION))
typedef struct {
  vec2 pos, vel;
  u32 jumps, dashes;
  bool turned_left;
  PlayerState state;
  RenderTarget render;
} Player;

typedef struct {
  u64 width, height;
  i64 x_origin, y_origin;
} GameScreen;

typedef struct {
  f32 dt;
  bool should_quit;
  bool is_initialized;
  Player player;
  Orbs orbs;
  GameScreen screen;
  RenderTarget background_render;
} GameState;

void game_update_and_render(GameState *state, GameInput *input);
#endif // _UDRI_H
