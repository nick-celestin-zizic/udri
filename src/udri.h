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

typedef struct {
  const u8 *data;
  u32 width, height;
  u32 gl_id;
} Bitmap;
