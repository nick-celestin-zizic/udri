#ifndef LA_H_
#define LA_H_

#include <math.h>

#ifndef LADEF
#define LADEF static inline
#endif // LADEF

LADEF float lerp(float a, float b, float t);
LADEF double lerp_f64(double a, double b, double t);
LADEF float max(float a, float b);
LADEF float min(float a, float b);
LADEF float clamp(float x, float a, float b);
LADEF double max_f64(double a, double b);
LADEF double min_f64(double a, double b);
LADEF double clamp_f64(double x, double a, double b);
LADEF int max_i32(int a, int b);
LADEF int min_i32(int a, int b);
LADEF int clamp_i32(int x, int a, int b);
LADEF unsigned int max_u32(unsigned int a, unsigned int b);
LADEF unsigned int min_u32(unsigned int a, unsigned int b);
LADEF unsigned int clamp_u32(unsigned int x, unsigned int a, unsigned int b);

typedef union {
  float all[2];
  struct { float x, y; };
  struct { float r, g; };
} vec2;

typedef union {
  double all[2];
  struct { double x, y; };
  struct { double r, g; };
} vec2_f64;

typedef union {
  int all[2];
  struct { int x, y; };
  struct { int r, g; };
} vec2_i32;

typedef union {
  unsigned int all[2];
  struct { unsigned int x, y; };
  struct { unsigned int r, g; };
} vec2_u32;

typedef union {
  float all[3];
  struct { float x, y, z; };
  struct { float r, g, b; };
} vec3;

typedef union {
  double all[3];
  struct { double x, y, z; };
  struct { double r, g, b; };
} vec3_f64;

typedef union {
  int all[3];
  struct { int x, y, z; };
  struct { int r, g, b; };
} vec3_i32;

typedef union {
  unsigned int all[3];
  struct { unsigned int x, y, z; };
  struct { unsigned int r, g, b; };
} vec3_u32;

typedef union {
  float all[4];
  struct { float x, y, z, w; };
  struct { float r, g, b, a; };
} vec4;

typedef union {
  double all[4];
  struct { double x, y, z, w; };
  struct { double r, g, b, a; };
} vec4_f64;

typedef union {
  int all[4];
  struct { int x, y, z, w; };
  struct { int r, g, b, a; };
} vec4_i32;

typedef union {
  unsigned int all[4];
  struct { unsigned int x, y, z, w; };
  struct { unsigned int r, g, b, a; };
} vec4_u32;


#define vec2_Fmt "make_vec2(%f, %f)"
#define vec2_Arg(v) (v).x, (v).y
LADEF vec2 make_vec2(float x, float y);
LADEF vec2 make_vec2_scalar(float x);
LADEF vec2 v2_to_v2_f64(vec2_f64 a);
LADEF vec2 v2_to_v2_i32(vec2_i32 a);
LADEF vec2 v2_to_v2_u32(vec2_u32 a);
LADEF vec2 v2_to_v3(vec3 a);
LADEF vec2 v2_to_v3_f64(vec3_f64 a);
LADEF vec2 v2_to_v3_i32(vec3_i32 a);
LADEF vec2 v2_to_v3_u32(vec3_u32 a);
LADEF vec2 v2_to_v4(vec4 a);
LADEF vec2 v2_to_v4_f64(vec4_f64 a);
LADEF vec2 v2_to_v4_i32(vec4_i32 a);
LADEF vec2 v2_to_v4_u32(vec4_u32 a);
LADEF vec2 vec2_add(vec2 a, vec2 b);
LADEF vec2 vec2_add_scalar(vec2 v, float s);
LADEF vec2 vec2_sub(vec2 a, vec2 b);
LADEF vec2 vec2_sub_scalar(vec2 v, float s);
LADEF vec2 vec2_mul(vec2 a, vec2 b);
LADEF vec2 vec2_mul_scalar(vec2 v, float s);
LADEF vec2 vec2_div(vec2 a, vec2 b);
LADEF vec2 vec2_div_scalar(vec2 v, float s);
LADEF vec2 make_vec2_sqrt(vec2 a);
LADEF vec2 make_vec2_pow(vec2 base, vec2 exp);
LADEF vec2 make_vec2_sin(vec2 a);
LADEF vec2 make_vec2_cos(vec2 a);
LADEF vec2 make_vec2_min(vec2 a, vec2 b);
LADEF vec2 make_vec2_max(vec2 a, vec2 b);
LADEF vec2 make_vec2_lerp(vec2 a, vec2 b, vec2 t);
LADEF vec2 make_vec2_floor(vec2 a);
LADEF vec2 make_vec2_ceil(vec2 a);
LADEF vec2 make_vec2_clamp(vec2 x, vec2 a, vec2 b);
LADEF float make_vec2_sqrlen(vec2 a);
LADEF float make_vec2_len(vec2 a);

#define vec2_f64_Fmt "make_vec2_f64(%lf, %lf)"
#define vec2_f64_Arg(v) (v).x, (v).y
LADEF vec2_f64 make_vec2_f64(double x, double y);
LADEF vec2_f64 make_vec2_f64_scalar(double x);
LADEF vec2_f64 v2_f64_to_v2(vec2 a);
LADEF vec2_f64 v2_f64_to_v2_i32(vec2_i32 a);
LADEF vec2_f64 v2_f64_to_v2_u32(vec2_u32 a);
LADEF vec2_f64 v2_f64_to_v3(vec3 a);
LADEF vec2_f64 v2_f64_to_v3_f64(vec3_f64 a);
LADEF vec2_f64 v2_f64_to_v3_i32(vec3_i32 a);
LADEF vec2_f64 v2_f64_to_v3_u32(vec3_u32 a);
LADEF vec2_f64 v2_f64_to_v4(vec4 a);
LADEF vec2_f64 v2_f64_to_v4_f64(vec4_f64 a);
LADEF vec2_f64 v2_f64_to_v4_i32(vec4_i32 a);
LADEF vec2_f64 v2_f64_to_v4_u32(vec4_u32 a);
LADEF vec2_f64 vec2_f64_add(vec2_f64 a, vec2_f64 b);
LADEF vec2_f64 vec2_f64_add_scalar(vec2_f64 v, double s);
LADEF vec2_f64 vec2_f64_sub(vec2_f64 a, vec2_f64 b);
LADEF vec2_f64 vec2_f64_sub_scalar(vec2_f64 v, double s);
LADEF vec2_f64 vec2_f64_mul(vec2_f64 a, vec2_f64 b);
LADEF vec2_f64 vec2_f64_mul_scalar(vec2_f64 v, double s);
LADEF vec2_f64 vec2_f64_div(vec2_f64 a, vec2_f64 b);
LADEF vec2_f64 vec2_f64_div_scalar(vec2_f64 v, double s);
LADEF vec2_f64 make_vec2_f64_sqrt(vec2_f64 a);
LADEF vec2_f64 make_vec2_f64_pow(vec2_f64 base, vec2_f64 exp);
LADEF vec2_f64 make_vec2_f64_sin(vec2_f64 a);
LADEF vec2_f64 make_vec2_f64_cos(vec2_f64 a);
LADEF vec2_f64 make_vec2_f64_min(vec2_f64 a, vec2_f64 b);
LADEF vec2_f64 make_vec2_f64_max(vec2_f64 a, vec2_f64 b);
LADEF vec2_f64 make_vec2_f64_lerp(vec2_f64 a, vec2_f64 b, vec2_f64 t);
LADEF vec2_f64 make_vec2_f64_floor(vec2_f64 a);
LADEF vec2_f64 make_vec2_f64_ceil(vec2_f64 a);
LADEF vec2_f64 make_vec2_f64_clamp(vec2_f64 x, vec2_f64 a, vec2_f64 b);
LADEF double make_vec2_f64_sqrlen(vec2_f64 a);
LADEF double make_vec2_f64_len(vec2_f64 a);

#define vec2_i32_Fmt "make_vec2_i32(%d, %d)"
#define vec2_i32_Arg(v) (v).x, (v).y
LADEF vec2_i32 make_vec2_i32(int x, int y);
LADEF vec2_i32 make_vec2_i32_scalar(int x);
LADEF vec2_i32 v2_i32_to_v2(vec2 a);
LADEF vec2_i32 v2_i32_to_v2_f64(vec2_f64 a);
LADEF vec2_i32 v2_i32_to_v2_u32(vec2_u32 a);
LADEF vec2_i32 v2_i32_to_v3(vec3 a);
LADEF vec2_i32 v2_i32_to_v3_f64(vec3_f64 a);
LADEF vec2_i32 v2_i32_to_v3_i32(vec3_i32 a);
LADEF vec2_i32 v2_i32_to_v3_u32(vec3_u32 a);
LADEF vec2_i32 v2_i32_to_v4(vec4 a);
LADEF vec2_i32 v2_i32_to_v4_f64(vec4_f64 a);
LADEF vec2_i32 v2_i32_to_v4_i32(vec4_i32 a);
LADEF vec2_i32 v2_i32_to_v4_u32(vec4_u32 a);
LADEF vec2_i32 vec2_i32_add(vec2_i32 a, vec2_i32 b);
LADEF vec2_i32 vec2_i32_add_scalar(vec2_i32 v, int s);
LADEF vec2_i32 vec2_i32_sub(vec2_i32 a, vec2_i32 b);
LADEF vec2_i32 vec2_i32_sub_scalar(vec2_i32 v, int s);
LADEF vec2_i32 vec2_i32_mul(vec2_i32 a, vec2_i32 b);
LADEF vec2_i32 vec2_i32_mul_scalar(vec2_i32 v, int s);
LADEF vec2_i32 vec2_i32_div(vec2_i32 a, vec2_i32 b);
LADEF vec2_i32 vec2_i32_div_scalar(vec2_i32 v, int s);
LADEF vec2_i32 make_vec2_i32_min(vec2_i32 a, vec2_i32 b);
LADEF vec2_i32 make_vec2_i32_max(vec2_i32 a, vec2_i32 b);
LADEF vec2_i32 make_vec2_i32_clamp(vec2_i32 x, vec2_i32 a, vec2_i32 b);
LADEF int make_vec2_i32_sqrlen(vec2_i32 a);

#define vec2_u32_Fmt "make_vec2_u32(%u, %u)"
#define vec2_u32_Arg(v) (v).x, (v).y
LADEF vec2_u32 make_vec2_u32(unsigned int x, unsigned int y);
LADEF vec2_u32 make_vec2_u32_scalar(unsigned int x);
LADEF vec2_u32 v2_u32_to_v2(vec2 a);
LADEF vec2_u32 v2_u32_to_v2_f64(vec2_f64 a);
LADEF vec2_u32 v2_u32_to_v2_i32(vec2_i32 a);
LADEF vec2_u32 v2_u32_to_v3(vec3 a);
LADEF vec2_u32 v2_u32_to_v3_f64(vec3_f64 a);
LADEF vec2_u32 v2_u32_to_v3_i32(vec3_i32 a);
LADEF vec2_u32 v2_u32_to_v3_u32(vec3_u32 a);
LADEF vec2_u32 v2_u32_to_v4(vec4 a);
LADEF vec2_u32 v2_u32_to_v4_f64(vec4_f64 a);
LADEF vec2_u32 v2_u32_to_v4_i32(vec4_i32 a);
LADEF vec2_u32 v2_u32_to_v4_u32(vec4_u32 a);
LADEF vec2_u32 vec2_u32_add(vec2_u32 a, vec2_u32 b);
LADEF vec2_u32 vec2_u32_add_scalar(vec2_u32 v, unsigned int s);
LADEF vec2_u32 vec2_u32_sub(vec2_u32 a, vec2_u32 b);
LADEF vec2_u32 vec2_u32_sub_scalar(vec2_u32 v, unsigned int s);
LADEF vec2_u32 vec2_u32_mul(vec2_u32 a, vec2_u32 b);
LADEF vec2_u32 vec2_u32_mul_scalar(vec2_u32 v, unsigned int s);
LADEF vec2_u32 vec2_u32_div(vec2_u32 a, vec2_u32 b);
LADEF vec2_u32 vec2_u32_div_scalar(vec2_u32 v, unsigned int s);
LADEF vec2_u32 make_vec2_u32_min(vec2_u32 a, vec2_u32 b);
LADEF vec2_u32 make_vec2_u32_max(vec2_u32 a, vec2_u32 b);
LADEF vec2_u32 make_vec2_u32_clamp(vec2_u32 x, vec2_u32 a, vec2_u32 b);
LADEF unsigned int make_vec2_u32_sqrlen(vec2_u32 a);

#define vec3_Fmt "make_vec3(%f, %f, %f)"
#define vec3_Arg(v) (v).x, (v).y, (v).z
LADEF vec3 make_vec3(float x, float y, float z);
LADEF vec3 make_vec3_scalar(float x);
LADEF vec3 v3_to_v2(vec2 a);
LADEF vec3 v3_to_v2_f64(vec2_f64 a);
LADEF vec3 v3_to_v2_i32(vec2_i32 a);
LADEF vec3 v3_to_v2_u32(vec2_u32 a);
LADEF vec3 v3_to_v3_f64(vec3_f64 a);
LADEF vec3 v3_to_v3_i32(vec3_i32 a);
LADEF vec3 v3_to_v3_u32(vec3_u32 a);
LADEF vec3 v3_to_v4(vec4 a);
LADEF vec3 v3_to_v4_f64(vec4_f64 a);
LADEF vec3 v3_to_v4_i32(vec4_i32 a);
LADEF vec3 v3_to_v4_u32(vec4_u32 a);
LADEF vec3 vec3_add(vec3 a, vec3 b);
LADEF vec3 vec3_add_scalar(vec3 v, float s);
LADEF vec3 vec3_sub(vec3 a, vec3 b);
LADEF vec3 vec3_sub_scalar(vec3 v, float s);
LADEF vec3 vec3_mul(vec3 a, vec3 b);
LADEF vec3 vec3_mul_scalar(vec3 v, float s);
LADEF vec3 vec3_div(vec3 a, vec3 b);
LADEF vec3 vec3_div_scalar(vec3 v, float s);
LADEF vec3 make_vec3_sqrt(vec3 a);
LADEF vec3 make_vec3_pow(vec3 base, vec3 exp);
LADEF vec3 make_vec3_sin(vec3 a);
LADEF vec3 make_vec3_cos(vec3 a);
LADEF vec3 make_vec3_min(vec3 a, vec3 b);
LADEF vec3 make_vec3_max(vec3 a, vec3 b);
LADEF vec3 make_vec3_lerp(vec3 a, vec3 b, vec3 t);
LADEF vec3 make_vec3_floor(vec3 a);
LADEF vec3 make_vec3_ceil(vec3 a);
LADEF vec3 make_vec3_clamp(vec3 x, vec3 a, vec3 b);
LADEF float make_vec3_sqrlen(vec3 a);
LADEF float make_vec3_len(vec3 a);

#define vec3_f64_Fmt "make_vec3_f64(%lf, %lf, %lf)"
#define vec3_f64_Arg(v) (v).x, (v).y, (v).z
LADEF vec3_f64 make_vec3_f64(double x, double y, double z);
LADEF vec3_f64 make_vec3_f64_scalar(double x);
LADEF vec3_f64 v3_f64_to_v2(vec2 a);
LADEF vec3_f64 v3_f64_to_v2_f64(vec2_f64 a);
LADEF vec3_f64 v3_f64_to_v2_i32(vec2_i32 a);
LADEF vec3_f64 v3_f64_to_v2_u32(vec2_u32 a);
LADEF vec3_f64 v3_f64_to_v3(vec3 a);
LADEF vec3_f64 v3_f64_to_v3_i32(vec3_i32 a);
LADEF vec3_f64 v3_f64_to_v3_u32(vec3_u32 a);
LADEF vec3_f64 v3_f64_to_v4(vec4 a);
LADEF vec3_f64 v3_f64_to_v4_f64(vec4_f64 a);
LADEF vec3_f64 v3_f64_to_v4_i32(vec4_i32 a);
LADEF vec3_f64 v3_f64_to_v4_u32(vec4_u32 a);
LADEF vec3_f64 vec3_f64_add(vec3_f64 a, vec3_f64 b);
LADEF vec3_f64 vec3_f64_add_scalar(vec3_f64 v, double s);
LADEF vec3_f64 vec3_f64_sub(vec3_f64 a, vec3_f64 b);
LADEF vec3_f64 vec3_f64_sub_scalar(vec3_f64 v, double s);
LADEF vec3_f64 vec3_f64_mul(vec3_f64 a, vec3_f64 b);
LADEF vec3_f64 vec3_f64_mul_scalar(vec3_f64 v, double s);
LADEF vec3_f64 vec3_f64_div(vec3_f64 a, vec3_f64 b);
LADEF vec3_f64 vec3_f64_div_scalar(vec3_f64 v, double s);
LADEF vec3_f64 make_vec3_f64_sqrt(vec3_f64 a);
LADEF vec3_f64 make_vec3_f64_pow(vec3_f64 base, vec3_f64 exp);
LADEF vec3_f64 make_vec3_f64_sin(vec3_f64 a);
LADEF vec3_f64 make_vec3_f64_cos(vec3_f64 a);
LADEF vec3_f64 make_vec3_f64_min(vec3_f64 a, vec3_f64 b);
LADEF vec3_f64 make_vec3_f64_max(vec3_f64 a, vec3_f64 b);
LADEF vec3_f64 make_vec3_f64_lerp(vec3_f64 a, vec3_f64 b, vec3_f64 t);
LADEF vec3_f64 make_vec3_f64_floor(vec3_f64 a);
LADEF vec3_f64 make_vec3_f64_ceil(vec3_f64 a);
LADEF vec3_f64 make_vec3_f64_clamp(vec3_f64 x, vec3_f64 a, vec3_f64 b);
LADEF double make_vec3_f64_sqrlen(vec3_f64 a);
LADEF double make_vec3_f64_len(vec3_f64 a);

#define vec3_i32_Fmt "make_vec3_i32(%d, %d, %d)"
#define vec3_i32_Arg(v) (v).x, (v).y, (v).z
LADEF vec3_i32 make_vec3_i32(int x, int y, int z);
LADEF vec3_i32 make_vec3_i32_scalar(int x);
LADEF vec3_i32 v3_i32_to_v2(vec2 a);
LADEF vec3_i32 v3_i32_to_v2_f64(vec2_f64 a);
LADEF vec3_i32 v3_i32_to_v2_i32(vec2_i32 a);
LADEF vec3_i32 v3_i32_to_v2_u32(vec2_u32 a);
LADEF vec3_i32 v3_i32_to_v3(vec3 a);
LADEF vec3_i32 v3_i32_to_v3_f64(vec3_f64 a);
LADEF vec3_i32 v3_i32_to_v3_u32(vec3_u32 a);
LADEF vec3_i32 v3_i32_to_v4(vec4 a);
LADEF vec3_i32 v3_i32_to_v4_f64(vec4_f64 a);
LADEF vec3_i32 v3_i32_to_v4_i32(vec4_i32 a);
LADEF vec3_i32 v3_i32_to_v4_u32(vec4_u32 a);
LADEF vec3_i32 vec3_i32_add(vec3_i32 a, vec3_i32 b);
LADEF vec3_i32 vec3_i32_add_scalar(vec3_i32 v, int s);
LADEF vec3_i32 vec3_i32_sub(vec3_i32 a, vec3_i32 b);
LADEF vec3_i32 vec3_i32_sub_scalar(vec3_i32 v, int s);
LADEF vec3_i32 vec3_i32_mul(vec3_i32 a, vec3_i32 b);
LADEF vec3_i32 vec3_i32_mul_scalar(vec3_i32 v, int s);
LADEF vec3_i32 vec3_i32_div(vec3_i32 a, vec3_i32 b);
LADEF vec3_i32 vec3_i32_div_scalar(vec3_i32 v, int s);
LADEF vec3_i32 make_vec3_i32_min(vec3_i32 a, vec3_i32 b);
LADEF vec3_i32 make_vec3_i32_max(vec3_i32 a, vec3_i32 b);
LADEF vec3_i32 make_vec3_i32_clamp(vec3_i32 x, vec3_i32 a, vec3_i32 b);
LADEF int make_vec3_i32_sqrlen(vec3_i32 a);

#define vec3_u32_Fmt "make_vec3_u32(%u, %u, %u)"
#define vec3_u32_Arg(v) (v).x, (v).y, (v).z
LADEF vec3_u32 make_vec3_u32(unsigned int x, unsigned int y, unsigned int z);
LADEF vec3_u32 make_vec3_u32_scalar(unsigned int x);
LADEF vec3_u32 v3_u32_to_v2(vec2 a);
LADEF vec3_u32 v3_u32_to_v2_f64(vec2_f64 a);
LADEF vec3_u32 v3_u32_to_v2_i32(vec2_i32 a);
LADEF vec3_u32 v3_u32_to_v2_u32(vec2_u32 a);
LADEF vec3_u32 v3_u32_to_v3(vec3 a);
LADEF vec3_u32 v3_u32_to_v3_f64(vec3_f64 a);
LADEF vec3_u32 v3_u32_to_v3_i32(vec3_i32 a);
LADEF vec3_u32 v3_u32_to_v4(vec4 a);
LADEF vec3_u32 v3_u32_to_v4_f64(vec4_f64 a);
LADEF vec3_u32 v3_u32_to_v4_i32(vec4_i32 a);
LADEF vec3_u32 v3_u32_to_v4_u32(vec4_u32 a);
LADEF vec3_u32 vec3_u32_add(vec3_u32 a, vec3_u32 b);
LADEF vec3_u32 vec3_u32_add_scalar(vec3_u32 v, unsigned int s);
LADEF vec3_u32 vec3_u32_sub(vec3_u32 a, vec3_u32 b);
LADEF vec3_u32 vec3_u32_sub_scalar(vec3_u32 v, unsigned int s);
LADEF vec3_u32 vec3_u32_mul(vec3_u32 a, vec3_u32 b);
LADEF vec3_u32 vec3_u32_mul_scalar(vec3_u32 v, unsigned int s);
LADEF vec3_u32 vec3_u32_div(vec3_u32 a, vec3_u32 b);
LADEF vec3_u32 vec3_u32_div_scalar(vec3_u32 v, unsigned int s);
LADEF vec3_u32 make_vec3_u32_min(vec3_u32 a, vec3_u32 b);
LADEF vec3_u32 make_vec3_u32_max(vec3_u32 a, vec3_u32 b);
LADEF vec3_u32 make_vec3_u32_clamp(vec3_u32 x, vec3_u32 a, vec3_u32 b);
LADEF unsigned int make_vec3_u32_sqrlen(vec3_u32 a);

#define vec4_Fmt "make_vec4(%f, %f, %f, %f)"
#define vec4_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF vec4 make_vec4(float x, float y, float z, float w);
LADEF vec4 make_vec4_scalar(float x);
LADEF vec4 v4_to_v2(vec2 a);
LADEF vec4 v4_to_v2_f64(vec2_f64 a);
LADEF vec4 v4_to_v2_i32(vec2_i32 a);
LADEF vec4 v4_to_v2_u32(vec2_u32 a);
LADEF vec4 v4_to_v3(vec3 a);
LADEF vec4 v4_to_v3_f64(vec3_f64 a);
LADEF vec4 v4_to_v3_i32(vec3_i32 a);
LADEF vec4 v4_to_v3_u32(vec3_u32 a);
LADEF vec4 v4_to_v4_f64(vec4_f64 a);
LADEF vec4 v4_to_v4_i32(vec4_i32 a);
LADEF vec4 v4_to_v4_u32(vec4_u32 a);
LADEF vec4 vec4_add(vec4 a, vec4 b);
LADEF vec4 vec4_add_scalar(vec4 v, float s);
LADEF vec4 vec4_sub(vec4 a, vec4 b);
LADEF vec4 vec4_sub_scalar(vec4 v, float s);
LADEF vec4 vec4_mul(vec4 a, vec4 b);
LADEF vec4 vec4_mul_scalar(vec4 v, float s);
LADEF vec4 vec4_div(vec4 a, vec4 b);
LADEF vec4 vec4_div_scalar(vec4 v, float s);
LADEF vec4 make_vec4_sqrt(vec4 a);
LADEF vec4 make_vec4_pow(vec4 base, vec4 exp);
LADEF vec4 make_vec4_sin(vec4 a);
LADEF vec4 make_vec4_cos(vec4 a);
LADEF vec4 make_vec4_min(vec4 a, vec4 b);
LADEF vec4 make_vec4_max(vec4 a, vec4 b);
LADEF vec4 make_vec4_lerp(vec4 a, vec4 b, vec4 t);
LADEF vec4 make_vec4_floor(vec4 a);
LADEF vec4 make_vec4_ceil(vec4 a);
LADEF vec4 make_vec4_clamp(vec4 x, vec4 a, vec4 b);
LADEF float make_vec4_sqrlen(vec4 a);
LADEF float make_vec4_len(vec4 a);

#define vec4_f64_Fmt "make_vec4_f64(%lf, %lf, %lf, %lf)"
#define vec4_f64_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF vec4_f64 make_vec4_f64(double x, double y, double z, double w);
LADEF vec4_f64 make_vec4_f64_scalar(double x);
LADEF vec4_f64 v4_f64_to_v2(vec2 a);
LADEF vec4_f64 v4_f64_to_v2_f64(vec2_f64 a);
LADEF vec4_f64 v4_f64_to_v2_i32(vec2_i32 a);
LADEF vec4_f64 v4_f64_to_v2_u32(vec2_u32 a);
LADEF vec4_f64 v4_f64_to_v3(vec3 a);
LADEF vec4_f64 v4_f64_to_v3_f64(vec3_f64 a);
LADEF vec4_f64 v4_f64_to_v3_i32(vec3_i32 a);
LADEF vec4_f64 v4_f64_to_v3_u32(vec3_u32 a);
LADEF vec4_f64 v4_f64_to_v4(vec4 a);
LADEF vec4_f64 v4_f64_to_v4_i32(vec4_i32 a);
LADEF vec4_f64 v4_f64_to_v4_u32(vec4_u32 a);
LADEF vec4_f64 vec4_f64_add(vec4_f64 a, vec4_f64 b);
LADEF vec4_f64 vec4_f64_add_scalar(vec4_f64 v, double s);
LADEF vec4_f64 vec4_f64_sub(vec4_f64 a, vec4_f64 b);
LADEF vec4_f64 vec4_f64_sub_scalar(vec4_f64 v, double s);
LADEF vec4_f64 vec4_f64_mul(vec4_f64 a, vec4_f64 b);
LADEF vec4_f64 vec4_f64_mul_scalar(vec4_f64 v, double s);
LADEF vec4_f64 vec4_f64_div(vec4_f64 a, vec4_f64 b);
LADEF vec4_f64 vec4_f64_div_scalar(vec4_f64 v, double s);
LADEF vec4_f64 make_vec4_f64_sqrt(vec4_f64 a);
LADEF vec4_f64 make_vec4_f64_pow(vec4_f64 base, vec4_f64 exp);
LADEF vec4_f64 make_vec4_f64_sin(vec4_f64 a);
LADEF vec4_f64 make_vec4_f64_cos(vec4_f64 a);
LADEF vec4_f64 make_vec4_f64_min(vec4_f64 a, vec4_f64 b);
LADEF vec4_f64 make_vec4_f64_max(vec4_f64 a, vec4_f64 b);
LADEF vec4_f64 make_vec4_f64_lerp(vec4_f64 a, vec4_f64 b, vec4_f64 t);
LADEF vec4_f64 make_vec4_f64_floor(vec4_f64 a);
LADEF vec4_f64 make_vec4_f64_ceil(vec4_f64 a);
LADEF vec4_f64 make_vec4_f64_clamp(vec4_f64 x, vec4_f64 a, vec4_f64 b);
LADEF double make_vec4_f64_sqrlen(vec4_f64 a);
LADEF double make_vec4_f64_len(vec4_f64 a);

#define vec4_i32_Fmt "make_vec4_i32(%d, %d, %d, %d)"
#define vec4_i32_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF vec4_i32 make_vec4_i32(int x, int y, int z, int w);
LADEF vec4_i32 make_vec4_i32_scalar(int x);
LADEF vec4_i32 v4_i32_to_v2(vec2 a);
LADEF vec4_i32 v4_i32_to_v2_f64(vec2_f64 a);
LADEF vec4_i32 v4_i32_to_v2_i32(vec2_i32 a);
LADEF vec4_i32 v4_i32_to_v2_u32(vec2_u32 a);
LADEF vec4_i32 v4_i32_to_v3(vec3 a);
LADEF vec4_i32 v4_i32_to_v3_f64(vec3_f64 a);
LADEF vec4_i32 v4_i32_to_v3_i32(vec3_i32 a);
LADEF vec4_i32 v4_i32_to_v3_u32(vec3_u32 a);
LADEF vec4_i32 v4_i32_to_v4(vec4 a);
LADEF vec4_i32 v4_i32_to_v4_f64(vec4_f64 a);
LADEF vec4_i32 v4_i32_to_v4_u32(vec4_u32 a);
LADEF vec4_i32 vec4_i32_add(vec4_i32 a, vec4_i32 b);
LADEF vec4_i32 vec4_i32_add_scalar(vec4_i32 v, int s);
LADEF vec4_i32 vec4_i32_sub(vec4_i32 a, vec4_i32 b);
LADEF vec4_i32 vec4_i32_sub_scalar(vec4_i32 v, int s);
LADEF vec4_i32 vec4_i32_mul(vec4_i32 a, vec4_i32 b);
LADEF vec4_i32 vec4_i32_mul_scalar(vec4_i32 v, int s);
LADEF vec4_i32 vec4_i32_div(vec4_i32 a, vec4_i32 b);
LADEF vec4_i32 vec4_i32_div_scalar(vec4_i32 v, int s);
LADEF vec4_i32 make_vec4_i32_min(vec4_i32 a, vec4_i32 b);
LADEF vec4_i32 make_vec4_i32_max(vec4_i32 a, vec4_i32 b);
LADEF vec4_i32 make_vec4_i32_clamp(vec4_i32 x, vec4_i32 a, vec4_i32 b);
LADEF int make_vec4_i32_sqrlen(vec4_i32 a);

#define vec4_u32_Fmt "make_vec4_u32(%u, %u, %u, %u)"
#define vec4_u32_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF vec4_u32 make_vec4_u32(unsigned int x, unsigned int y, unsigned int z, unsigned int w);
LADEF vec4_u32 make_vec4_u32_scalar(unsigned int x);
LADEF vec4_u32 v4_u32_to_v2(vec2 a);
LADEF vec4_u32 v4_u32_to_v2_f64(vec2_f64 a);
LADEF vec4_u32 v4_u32_to_v2_i32(vec2_i32 a);
LADEF vec4_u32 v4_u32_to_v2_u32(vec2_u32 a);
LADEF vec4_u32 v4_u32_to_v3(vec3 a);
LADEF vec4_u32 v4_u32_to_v3_f64(vec3_f64 a);
LADEF vec4_u32 v4_u32_to_v3_i32(vec3_i32 a);
LADEF vec4_u32 v4_u32_to_v3_u32(vec3_u32 a);
LADEF vec4_u32 v4_u32_to_v4(vec4 a);
LADEF vec4_u32 v4_u32_to_v4_f64(vec4_f64 a);
LADEF vec4_u32 v4_u32_to_v4_i32(vec4_i32 a);
LADEF vec4_u32 vec4_u32_add(vec4_u32 a, vec4_u32 b);
LADEF vec4_u32 vec4_u32_add_scalar(vec4_u32 v, unsigned int s);
LADEF vec4_u32 vec4_u32_sub(vec4_u32 a, vec4_u32 b);
LADEF vec4_u32 vec4_u32_sub_scalar(vec4_u32 v, unsigned int s);
LADEF vec4_u32 vec4_u32_mul(vec4_u32 a, vec4_u32 b);
LADEF vec4_u32 vec4_u32_mul_scalar(vec4_u32 v, unsigned int s);
LADEF vec4_u32 vec4_u32_div(vec4_u32 a, vec4_u32 b);
LADEF vec4_u32 vec4_u32_div_scalar(vec4_u32 v, unsigned int s);
LADEF vec4_u32 make_vec4_u32_min(vec4_u32 a, vec4_u32 b);
LADEF vec4_u32 make_vec4_u32_max(vec4_u32 a, vec4_u32 b);
LADEF vec4_u32 make_vec4_u32_clamp(vec4_u32 x, vec4_u32 a, vec4_u32 b);
LADEF unsigned int make_vec4_u32_sqrlen(vec4_u32 a);

#endif // LA_H_

