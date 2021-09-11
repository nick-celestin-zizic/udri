#include "udri.h"

// TODO video

// TODO audio

// input
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

static const u16 linux_keybinds[] = {
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
