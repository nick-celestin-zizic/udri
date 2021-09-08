#include <stdint.h>
#include <stddef.h>

typedef char byte;

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

#define ASPECT_WIDTH 16.0f
#define ASPECT_HEIGHT 9.0f
#define ASPECT_RATIO (ASPECT_WIDTH / ASPECT_HEIGHT)

#define XKEY_ESCAPE         9
#define XKEY_LSHIFT         50
#define XKEY_A              38
#define XKEY_S              39
#define XKEY_D              40
#define XKEY_V              55
#define XKEY_B              56
#define XKEY_P              33
#define XKEY_LEFT_BRACKET   34
#define XKEY_RIGHT_BRACKET  35
#define XKEY_BACKSLASH      51
#define XKEY_PERIOD         60
#define XKEY_SLASH          61
#define XKEY_L              46
#define XKEY_COMMA          59
#define XKEY_RALT           108

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

static const u16 keybinds[] = {
  [XKEY_ESCAPE] = UDRI_BUTTON_START,
  [XKEY_LSHIFT] = UDRI_BUTTON_L,
  
  [XKEY_BACKSLASH] = UDRI_BUTTON_UP,
  [XKEY_A]         = UDRI_BUTTON_LEFT,
  [XKEY_S]         = UDRI_BUTTON_DOWN,
  [XKEY_D]         = UDRI_BUTTON_RIGHT,
  
  [XKEY_V] = UDRI_BUTTON_MOD_X,
  [XKEY_B] = UDRI_BUTTON_MOD_Y,

  [XKEY_PERIOD]        = UDRI_BUTTON_A,
  [XKEY_P]             = UDRI_BUTTON_B,
  [XKEY_LEFT_BRACKET]  = UDRI_BUTTON_X,
  [XKEY_RIGHT_BRACKET] = UDRI_BUTTON_Z,
  
  [XKEY_SLASH] = UDRI_BUTTON_C_RIGHT,
  [XKEY_L]     = UDRI_BUTTON_C_UP,
  [XKEY_COMMA] = UDRI_BUTTON_C_LEFT,
  [XKEY_RALT]  = UDRI_BUTTON_C_DOWN,
};

#define WINDOW_NAME "udri"
