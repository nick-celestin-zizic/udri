#include "la.h"
LADEF float lerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

LADEF double lerp_f64(double a, double b, double t)
{
    return a + (b - a) * t;
}

LADEF float max(float a, float b)
{
    return a < b ? b : a;
}

LADEF float min(float a, float b)
{
    return a < b ? a : b;
}

LADEF float clamp(float x, float a, float b)
{
    return min(max(a, x), b);
}

LADEF double max_f64(double a, double b)
{
    return a < b ? b : a;
}

LADEF double min_f64(double a, double b)
{
    return a < b ? a : b;
}

LADEF double clamp_f64(double x, double a, double b)
{
    return min_f64(max_f64(a, x), b);
}

LADEF int max_i32(int a, int b)
{
    return a < b ? b : a;
}

LADEF int min_i32(int a, int b)
{
    return a < b ? a : b;
}

LADEF int clamp_i32(int x, int a, int b)
{
    return min_i32(max_i32(a, x), b);
}

LADEF unsigned int max_u32(unsigned int a, unsigned int b)
{
    return a < b ? b : a;
}

LADEF unsigned int min_u32(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

LADEF unsigned int clamp_u32(unsigned int x, unsigned int a, unsigned int b)
{
    return min_u32(max_u32(a, x), b);
}

LADEF vec2 make_vec2(float x, float y)
{
    vec2 v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF vec2 make_vec2_scalar(float x)
{
    return make_vec2(x, x);
}

LADEF vec2 v2_to_v2_f64(vec2_f64 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v2_i32(vec2_i32 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v2_u32(vec2_u32 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v3(vec3 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v3_f64(vec3_f64 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v3_i32(vec3_i32 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v3_u32(vec3_u32 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v4(vec4 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v4_f64(vec4_f64 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v4_i32(vec4_i32 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 v2_to_v4_u32(vec4_u32 a)
{
    vec2 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}

LADEF vec2 vec2_add(vec2 a, vec2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
LADEF vec2 vec2_add_scalar(vec2 v, float s)
{
    v.x += s;
    v.y += s;
    return v;
}

LADEF vec2 vec2_sub(vec2 a, vec2 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
LADEF vec2 vec2_sub_scalar(vec2 v, float s)
{
    v.x -= s;
    v.y -= s;
    return v;
}

LADEF vec2 vec2_mul(vec2 a, vec2 b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
LADEF vec2 vec2_mul_scalar(vec2 v, float s)
{
    v.x *= s;
    v.y *= s;
    return v;
}

LADEF vec2 vec2_div(vec2 a, vec2 b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
LADEF vec2 vec2_div_scalar(vec2 v, float s)
{
    v.x /= s;
    v.y /= s;
    return v;
}

LADEF vec2 make_vec2_sqrt(vec2 a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    return a;
}

LADEF vec2 make_vec2_pow(vec2 base, vec2 exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    return base;
}

LADEF vec2 make_vec2_sin(vec2 a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    return a;
}

LADEF vec2 make_vec2_cos(vec2 a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    return a;
}

LADEF vec2 make_vec2_min(vec2 a, vec2 b)
{
    a.x = min(a.x, b.x);
    a.y = min(a.y, b.y);
    return a;
}

LADEF vec2 make_vec2_max(vec2 a, vec2 b)
{
    a.x = max(a.x, b.x);
    a.y = max(a.y, b.y);
    return a;
}

LADEF vec2 make_vec2_lerp(vec2 a, vec2 b, vec2 t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    return a;
}

LADEF vec2 make_vec2_floor(vec2 a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    return a;
}

LADEF vec2 make_vec2_ceil(vec2 a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    return a;
}

LADEF vec2 make_vec2_clamp(vec2 x, vec2 a, vec2 b)
{
    x.x = clamp(x.x, a.x, b.x);
    x.y = clamp(x.y, a.y, b.y);
    return x;
}

LADEF float make_vec2_sqrlen(vec2 a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF float make_vec2_len(vec2 a)
{
    return sqrtf(make_vec2_sqrlen(a));
}

LADEF vec2_f64 make_vec2_f64(double x, double y)
{
    vec2_f64 v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF vec2_f64 make_vec2_f64_scalar(double x)
{
    return make_vec2_f64(x, x);
}

LADEF vec2_f64 v2_f64_to_v2(vec2 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v2_i32(vec2_i32 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v2_u32(vec2_u32 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v3(vec3 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v3_f64(vec3_f64 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v3_i32(vec3_i32 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v3_u32(vec3_u32 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v4(vec4 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v4_f64(vec4_f64 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v4_i32(vec4_i32 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 v2_f64_to_v4_u32(vec4_u32 a)
{
    vec2_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}

LADEF vec2_f64 vec2_f64_add(vec2_f64 a, vec2_f64 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
LADEF vec2_f64 vec2_f64_add_scalar(vec2_f64 v, double s)
{
    v.x += s;
    v.y += s;
    return v;
}

LADEF vec2_f64 vec2_f64_sub(vec2_f64 a, vec2_f64 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
LADEF vec2_f64 vec2_f64_sub_scalar(vec2_f64 v, double s)
{
    v.x -= s;
    v.y -= s;
    return v;
}

LADEF vec2_f64 vec2_f64_mul(vec2_f64 a, vec2_f64 b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
LADEF vec2_f64 vec2_f64_mul_scalar(vec2_f64 v, double s)
{
    v.x *= s;
    v.y *= s;
    return v;
}

LADEF vec2_f64 vec2_f64_div(vec2_f64 a, vec2_f64 b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
LADEF vec2_f64 vec2_f64_div_scalar(vec2_f64 v, double s)
{
    v.x /= s;
    v.y /= s;
    return v;
}

LADEF vec2_f64 make_vec2_f64_sqrt(vec2_f64 a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_pow(vec2_f64 base, vec2_f64 exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    return base;
}

LADEF vec2_f64 make_vec2_f64_sin(vec2_f64 a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_cos(vec2_f64 a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_min(vec2_f64 a, vec2_f64 b)
{
    a.x = min_f64(a.x, b.x);
    a.y = min_f64(a.y, b.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_max(vec2_f64 a, vec2_f64 b)
{
    a.x = max_f64(a.x, b.x);
    a.y = max_f64(a.y, b.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_lerp(vec2_f64 a, vec2_f64 b, vec2_f64 t)
{
    a.x = lerp_f64(a.x, b.x, t.x);
    a.y = lerp_f64(a.y, b.y, t.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_floor(vec2_f64 a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_ceil(vec2_f64 a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    return a;
}

LADEF vec2_f64 make_vec2_f64_clamp(vec2_f64 x, vec2_f64 a, vec2_f64 b)
{
    x.x = clamp_f64(x.x, a.x, b.x);
    x.y = clamp_f64(x.y, a.y, b.y);
    return x;
}

LADEF double make_vec2_f64_sqrlen(vec2_f64 a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF double make_vec2_f64_len(vec2_f64 a)
{
    return sqrtl(make_vec2_f64_sqrlen(a));
}

LADEF vec2_i32 make_vec2_i32(int x, int y)
{
    vec2_i32 v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF vec2_i32 make_vec2_i32_scalar(int x)
{
    return make_vec2_i32(x, x);
}

LADEF vec2_i32 v2_i32_to_v2(vec2 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v2_f64(vec2_f64 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v2_u32(vec2_u32 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v3(vec3 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v3_f64(vec3_f64 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v3_i32(vec3_i32 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v3_u32(vec3_u32 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v4(vec4 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v4_f64(vec4_f64 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v4_i32(vec4_i32 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 v2_i32_to_v4_u32(vec4_u32 a)
{
    vec2_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}

LADEF vec2_i32 vec2_i32_add(vec2_i32 a, vec2_i32 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
LADEF vec2_i32 vec2_i32_add_scalar(vec2_i32 v, int s)
{
    v.x += s;
    v.y += s;
    return v;
}

LADEF vec2_i32 vec2_i32_sub(vec2_i32 a, vec2_i32 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
LADEF vec2_i32 vec2_i32_sub_scalar(vec2_i32 v, int s)
{
    v.x -= s;
    v.y -= s;
    return v;
}

LADEF vec2_i32 vec2_i32_mul(vec2_i32 a, vec2_i32 b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
LADEF vec2_i32 vec2_i32_mul_scalar(vec2_i32 v, int s)
{
    v.x *= s;
    v.y *= s;
    return v;
}

LADEF vec2_i32 vec2_i32_div(vec2_i32 a, vec2_i32 b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
LADEF vec2_i32 vec2_i32_div_scalar(vec2_i32 v, int s)
{
    v.x /= s;
    v.y /= s;
    return v;
}

LADEF vec2_i32 make_vec2_i32_min(vec2_i32 a, vec2_i32 b)
{
    a.x = min_i32(a.x, b.x);
    a.y = min_i32(a.y, b.y);
    return a;
}

LADEF vec2_i32 make_vec2_i32_max(vec2_i32 a, vec2_i32 b)
{
    a.x = max_i32(a.x, b.x);
    a.y = max_i32(a.y, b.y);
    return a;
}

LADEF vec2_i32 make_vec2_i32_clamp(vec2_i32 x, vec2_i32 a, vec2_i32 b)
{
    x.x = clamp_i32(x.x, a.x, b.x);
    x.y = clamp_i32(x.y, a.y, b.y);
    return x;
}

LADEF int make_vec2_i32_sqrlen(vec2_i32 a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF vec2_u32 make_vec2_u32(unsigned int x, unsigned int y)
{
    vec2_u32 v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF vec2_u32 make_vec2_u32_scalar(unsigned int x)
{
    return make_vec2_u32(x, x);
}

LADEF vec2_u32 v2_u32_to_v2(vec2 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v2_f64(vec2_f64 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v2_i32(vec2_i32 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v3(vec3 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v3_f64(vec3_f64 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v3_i32(vec3_i32 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v3_u32(vec3_u32 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v4(vec4 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v4_f64(vec4_f64 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v4_i32(vec4_i32 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 v2_u32_to_v4_u32(vec4_u32 a)
{
    vec2_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}

LADEF vec2_u32 vec2_u32_add(vec2_u32 a, vec2_u32 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
LADEF vec2_u32 vec2_u32_add_scalar(vec2_u32 v, unsigned int s)
{
    v.x += s;
    v.y += s;
    return v;
}

LADEF vec2_u32 vec2_u32_sub(vec2_u32 a, vec2_u32 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
LADEF vec2_u32 vec2_u32_sub_scalar(vec2_u32 v, unsigned int s)
{
    v.x -= s;
    v.y -= s;
    return v;
}

LADEF vec2_u32 vec2_u32_mul(vec2_u32 a, vec2_u32 b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}
LADEF vec2_u32 vec2_u32_mul_scalar(vec2_u32 v, unsigned int s)
{
    v.x *= s;
    v.y *= s;
    return v;
}

LADEF vec2_u32 vec2_u32_div(vec2_u32 a, vec2_u32 b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}
LADEF vec2_u32 vec2_u32_div_scalar(vec2_u32 v, unsigned int s)
{
    v.x /= s;
    v.y /= s;
    return v;
}

LADEF vec2_u32 make_vec2_u32_min(vec2_u32 a, vec2_u32 b)
{
    a.x = min_u32(a.x, b.x);
    a.y = min_u32(a.y, b.y);
    return a;
}

LADEF vec2_u32 make_vec2_u32_max(vec2_u32 a, vec2_u32 b)
{
    a.x = max_u32(a.x, b.x);
    a.y = max_u32(a.y, b.y);
    return a;
}

LADEF vec2_u32 make_vec2_u32_clamp(vec2_u32 x, vec2_u32 a, vec2_u32 b)
{
    x.x = clamp_u32(x.x, a.x, b.x);
    x.y = clamp_u32(x.y, a.y, b.y);
    return x;
}

LADEF unsigned int make_vec2_u32_sqrlen(vec2_u32 a)
{
    return a.x*a.x + a.y*a.y;
}

LADEF vec3 make_vec3(float x, float y, float z)
{
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF vec3 make_vec3_scalar(float x)
{
    return make_vec3(x, x, x);
}

LADEF vec3 v3_to_v2(vec2 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF vec3 v3_to_v2_f64(vec2_f64 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF vec3 v3_to_v2_i32(vec2_i32 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF vec3 v3_to_v2_u32(vec2_u32 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}

LADEF vec3 v3_to_v3_f64(vec3_f64 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 v3_to_v3_i32(vec3_i32 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 v3_to_v3_u32(vec3_u32 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 v3_to_v4(vec4 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 v3_to_v4_f64(vec4_f64 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 v3_to_v4_i32(vec4_i32 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 v3_to_v4_u32(vec4_u32 a)
{
    vec3 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}

LADEF vec3 vec3_add(vec3 a, vec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
LADEF vec3 vec3_add_scalar(vec3 v, float s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    return v;
}

LADEF vec3 vec3_sub(vec3 a, vec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
LADEF vec3 vec3_sub_scalar(vec3 v, float s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    return v;
}

LADEF vec3 vec3_mul(vec3 a, vec3 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
LADEF vec3 vec3_mul_scalar(vec3 v, float s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return v;
}

LADEF vec3 vec3_div(vec3 a, vec3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
LADEF vec3 vec3_div_scalar(vec3 v, float s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    return v;
}

LADEF vec3 make_vec3_sqrt(vec3 a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    return a;
}

LADEF vec3 make_vec3_pow(vec3 base, vec3 exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    return base;
}

LADEF vec3 make_vec3_sin(vec3 a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    return a;
}

LADEF vec3 make_vec3_cos(vec3 a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    return a;
}

LADEF vec3 make_vec3_min(vec3 a, vec3 b)
{
    a.x = min(a.x, b.x);
    a.y = min(a.y, b.y);
    a.z = min(a.z, b.z);
    return a;
}

LADEF vec3 make_vec3_max(vec3 a, vec3 b)
{
    a.x = max(a.x, b.x);
    a.y = max(a.y, b.y);
    a.z = max(a.z, b.z);
    return a;
}

LADEF vec3 make_vec3_lerp(vec3 a, vec3 b, vec3 t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    return a;
}

LADEF vec3 make_vec3_floor(vec3 a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    return a;
}

LADEF vec3 make_vec3_ceil(vec3 a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    return a;
}

LADEF vec3 make_vec3_clamp(vec3 x, vec3 a, vec3 b)
{
    x.x = clamp(x.x, a.x, b.x);
    x.y = clamp(x.y, a.y, b.y);
    x.z = clamp(x.z, a.z, b.z);
    return x;
}

LADEF float make_vec3_sqrlen(vec3 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF float make_vec3_len(vec3 a)
{
    return sqrtf(make_vec3_sqrlen(a));
}

LADEF vec3_f64 make_vec3_f64(double x, double y, double z)
{
    vec3_f64 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF vec3_f64 make_vec3_f64_scalar(double x)
{
    return make_vec3_f64(x, x, x);
}

LADEF vec3_f64 v3_f64_to_v2(vec2 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF vec3_f64 v3_f64_to_v2_f64(vec2_f64 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF vec3_f64 v3_f64_to_v2_i32(vec2_i32 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF vec3_f64 v3_f64_to_v2_u32(vec2_u32 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}

LADEF vec3_f64 v3_f64_to_v3(vec3 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 v3_f64_to_v3_i32(vec3_i32 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 v3_f64_to_v3_u32(vec3_u32 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 v3_f64_to_v4(vec4 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 v3_f64_to_v4_f64(vec4_f64 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 v3_f64_to_v4_i32(vec4_i32 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 v3_f64_to_v4_u32(vec4_u32 a)
{
    vec3_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}

LADEF vec3_f64 vec3_f64_add(vec3_f64 a, vec3_f64 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
LADEF vec3_f64 vec3_f64_add_scalar(vec3_f64 v, double s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    return v;
}

LADEF vec3_f64 vec3_f64_sub(vec3_f64 a, vec3_f64 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
LADEF vec3_f64 vec3_f64_sub_scalar(vec3_f64 v, double s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    return v;
}

LADEF vec3_f64 vec3_f64_mul(vec3_f64 a, vec3_f64 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
LADEF vec3_f64 vec3_f64_mul_scalar(vec3_f64 v, double s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return v;
}

LADEF vec3_f64 vec3_f64_div(vec3_f64 a, vec3_f64 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
LADEF vec3_f64 vec3_f64_div_scalar(vec3_f64 v, double s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    return v;
}

LADEF vec3_f64 make_vec3_f64_sqrt(vec3_f64 a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_pow(vec3_f64 base, vec3_f64 exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    return base;
}

LADEF vec3_f64 make_vec3_f64_sin(vec3_f64 a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_cos(vec3_f64 a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_min(vec3_f64 a, vec3_f64 b)
{
    a.x = min_f64(a.x, b.x);
    a.y = min_f64(a.y, b.y);
    a.z = min_f64(a.z, b.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_max(vec3_f64 a, vec3_f64 b)
{
    a.x = max_f64(a.x, b.x);
    a.y = max_f64(a.y, b.y);
    a.z = max_f64(a.z, b.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_lerp(vec3_f64 a, vec3_f64 b, vec3_f64 t)
{
    a.x = lerp_f64(a.x, b.x, t.x);
    a.y = lerp_f64(a.y, b.y, t.y);
    a.z = lerp_f64(a.z, b.z, t.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_floor(vec3_f64 a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_ceil(vec3_f64 a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    return a;
}

LADEF vec3_f64 make_vec3_f64_clamp(vec3_f64 x, vec3_f64 a, vec3_f64 b)
{
    x.x = clamp_f64(x.x, a.x, b.x);
    x.y = clamp_f64(x.y, a.y, b.y);
    x.z = clamp_f64(x.z, a.z, b.z);
    return x;
}

LADEF double make_vec3_f64_sqrlen(vec3_f64 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF double make_vec3_f64_len(vec3_f64 a)
{
    return sqrtl(make_vec3_f64_sqrlen(a));
}

LADEF vec3_i32 make_vec3_i32(int x, int y, int z)
{
    vec3_i32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF vec3_i32 make_vec3_i32_scalar(int x)
{
    return make_vec3_i32(x, x, x);
}

LADEF vec3_i32 v3_i32_to_v2(vec2 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF vec3_i32 v3_i32_to_v2_f64(vec2_f64 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF vec3_i32 v3_i32_to_v2_i32(vec2_i32 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF vec3_i32 v3_i32_to_v2_u32(vec2_u32 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}

LADEF vec3_i32 v3_i32_to_v3(vec3 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 v3_i32_to_v3_f64(vec3_f64 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 v3_i32_to_v3_u32(vec3_u32 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 v3_i32_to_v4(vec4 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 v3_i32_to_v4_f64(vec4_f64 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 v3_i32_to_v4_i32(vec4_i32 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 v3_i32_to_v4_u32(vec4_u32 a)
{
    vec3_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}

LADEF vec3_i32 vec3_i32_add(vec3_i32 a, vec3_i32 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
LADEF vec3_i32 vec3_i32_add_scalar(vec3_i32 v, int s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    return v;
}

LADEF vec3_i32 vec3_i32_sub(vec3_i32 a, vec3_i32 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
LADEF vec3_i32 vec3_i32_sub_scalar(vec3_i32 v, int s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    return v;
}

LADEF vec3_i32 vec3_i32_mul(vec3_i32 a, vec3_i32 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
LADEF vec3_i32 vec3_i32_mul_scalar(vec3_i32 v, int s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return v;
}

LADEF vec3_i32 vec3_i32_div(vec3_i32 a, vec3_i32 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
LADEF vec3_i32 vec3_i32_div_scalar(vec3_i32 v, int s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    return v;
}

LADEF vec3_i32 make_vec3_i32_min(vec3_i32 a, vec3_i32 b)
{
    a.x = min_i32(a.x, b.x);
    a.y = min_i32(a.y, b.y);
    a.z = min_i32(a.z, b.z);
    return a;
}

LADEF vec3_i32 make_vec3_i32_max(vec3_i32 a, vec3_i32 b)
{
    a.x = max_i32(a.x, b.x);
    a.y = max_i32(a.y, b.y);
    a.z = max_i32(a.z, b.z);
    return a;
}

LADEF vec3_i32 make_vec3_i32_clamp(vec3_i32 x, vec3_i32 a, vec3_i32 b)
{
    x.x = clamp_i32(x.x, a.x, b.x);
    x.y = clamp_i32(x.y, a.y, b.y);
    x.z = clamp_i32(x.z, a.z, b.z);
    return x;
}

LADEF int make_vec3_i32_sqrlen(vec3_i32 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF vec3_u32 make_vec3_u32(unsigned int x, unsigned int y, unsigned int z)
{
    vec3_u32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF vec3_u32 make_vec3_u32_scalar(unsigned int x)
{
    return make_vec3_u32(x, x, x);
}

LADEF vec3_u32 v3_u32_to_v2(vec2 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF vec3_u32 v3_u32_to_v2_f64(vec2_f64 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF vec3_u32 v3_u32_to_v2_i32(vec2_i32 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF vec3_u32 v3_u32_to_v2_u32(vec2_u32 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}

LADEF vec3_u32 v3_u32_to_v3(vec3 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 v3_u32_to_v3_f64(vec3_f64 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 v3_u32_to_v3_i32(vec3_i32 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 v3_u32_to_v4(vec4 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 v3_u32_to_v4_f64(vec4_f64 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 v3_u32_to_v4_i32(vec4_i32 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 v3_u32_to_v4_u32(vec4_u32 a)
{
    vec3_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}

LADEF vec3_u32 vec3_u32_add(vec3_u32 a, vec3_u32 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
LADEF vec3_u32 vec3_u32_add_scalar(vec3_u32 v, unsigned int s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    return v;
}

LADEF vec3_u32 vec3_u32_sub(vec3_u32 a, vec3_u32 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
LADEF vec3_u32 vec3_u32_sub_scalar(vec3_u32 v, unsigned int s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    return v;
}

LADEF vec3_u32 vec3_u32_mul(vec3_u32 a, vec3_u32 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}
LADEF vec3_u32 vec3_u32_mul_scalar(vec3_u32 v, unsigned int s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return v;
}

LADEF vec3_u32 vec3_u32_div(vec3_u32 a, vec3_u32 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}
LADEF vec3_u32 vec3_u32_div_scalar(vec3_u32 v, unsigned int s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    return v;
}

LADEF vec3_u32 make_vec3_u32_min(vec3_u32 a, vec3_u32 b)
{
    a.x = min_u32(a.x, b.x);
    a.y = min_u32(a.y, b.y);
    a.z = min_u32(a.z, b.z);
    return a;
}

LADEF vec3_u32 make_vec3_u32_max(vec3_u32 a, vec3_u32 b)
{
    a.x = max_u32(a.x, b.x);
    a.y = max_u32(a.y, b.y);
    a.z = max_u32(a.z, b.z);
    return a;
}

LADEF vec3_u32 make_vec3_u32_clamp(vec3_u32 x, vec3_u32 a, vec3_u32 b)
{
    x.x = clamp_u32(x.x, a.x, b.x);
    x.y = clamp_u32(x.y, a.y, b.y);
    x.z = clamp_u32(x.z, a.z, b.z);
    return x;
}

LADEF unsigned int make_vec3_u32_sqrlen(vec3_u32 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

LADEF vec4 make_vec4(float x, float y, float z, float w)
{
    vec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF vec4 make_vec4_scalar(float x)
{
    return make_vec4(x, x, x, x);
}

LADEF vec4 v4_to_v2(vec2 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v2_f64(vec2_f64 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v2_i32(vec2_i32 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v2_u32(vec2_u32 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v3(vec3 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v3_f64(vec3_f64 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v3_i32(vec3_i32 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v3_u32(vec3_u32 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}

LADEF vec4 v4_to_v4_f64(vec4_f64 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}

LADEF vec4 v4_to_v4_i32(vec4_i32 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}

LADEF vec4 v4_to_v4_u32(vec4_u32 a)
{
    vec4 result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}

LADEF vec4 vec4_add(vec4 a, vec4 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
LADEF vec4 vec4_add_scalar(vec4 v, float s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    v.w += s;
    return v;
}

LADEF vec4 vec4_sub(vec4 a, vec4 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
LADEF vec4 vec4_sub_scalar(vec4 v, float s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    v.w -= s;
    return v;
}

LADEF vec4 vec4_mul(vec4 a, vec4 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
LADEF vec4 vec4_mul_scalar(vec4 v, float s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    v.w *= s;
    return v;
}

LADEF vec4 vec4_div(vec4 a, vec4 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
LADEF vec4 vec4_div_scalar(vec4 v, float s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    v.w /= s;
    return v;
}

LADEF vec4 make_vec4_sqrt(vec4 a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    a.w = sqrtf(a.w);
    return a;
}

LADEF vec4 make_vec4_pow(vec4 base, vec4 exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    base.w = powf(base.w, exp.w);
    return base;
}

LADEF vec4 make_vec4_sin(vec4 a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    a.w = sinf(a.w);
    return a;
}

LADEF vec4 make_vec4_cos(vec4 a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    a.w = cosf(a.w);
    return a;
}

LADEF vec4 make_vec4_min(vec4 a, vec4 b)
{
    a.x = min(a.x, b.x);
    a.y = min(a.y, b.y);
    a.z = min(a.z, b.z);
    a.w = min(a.w, b.w);
    return a;
}

LADEF vec4 make_vec4_max(vec4 a, vec4 b)
{
    a.x = max(a.x, b.x);
    a.y = max(a.y, b.y);
    a.z = max(a.z, b.z);
    a.w = max(a.w, b.w);
    return a;
}

LADEF vec4 make_vec4_lerp(vec4 a, vec4 b, vec4 t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    a.w = lerp(a.w, b.w, t.w);
    return a;
}

LADEF vec4 make_vec4_floor(vec4 a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    a.w = floorf(a.w);
    return a;
}

LADEF vec4 make_vec4_ceil(vec4 a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    a.w = ceilf(a.w);
    return a;
}

LADEF vec4 make_vec4_clamp(vec4 x, vec4 a, vec4 b)
{
    x.x = clamp(x.x, a.x, b.x);
    x.y = clamp(x.y, a.y, b.y);
    x.z = clamp(x.z, a.z, b.z);
    x.w = clamp(x.w, a.w, b.w);
    return x;
}

LADEF float make_vec4_sqrlen(vec4 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF float make_vec4_len(vec4 a)
{
    return sqrtf(make_vec4_sqrlen(a));
}

LADEF vec4_f64 make_vec4_f64(double x, double y, double z, double w)
{
    vec4_f64 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF vec4_f64 make_vec4_f64_scalar(double x)
{
    return make_vec4_f64(x, x, x, x);
}

LADEF vec4_f64 v4_f64_to_v2(vec2 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v2_f64(vec2_f64 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v2_i32(vec2_i32 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v2_u32(vec2_u32 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v3(vec3 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v3_f64(vec3_f64 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v3_i32(vec3_i32 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v3_u32(vec3_u32 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}

LADEF vec4_f64 v4_f64_to_v4(vec4 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}

LADEF vec4_f64 v4_f64_to_v4_i32(vec4_i32 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}

LADEF vec4_f64 v4_f64_to_v4_u32(vec4_u32 a)
{
    vec4_f64 result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}

LADEF vec4_f64 vec4_f64_add(vec4_f64 a, vec4_f64 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
LADEF vec4_f64 vec4_f64_add_scalar(vec4_f64 v, double s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    v.w += s;
    return v;
}

LADEF vec4_f64 vec4_f64_sub(vec4_f64 a, vec4_f64 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
LADEF vec4_f64 vec4_f64_sub_scalar(vec4_f64 v, double s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    v.w -= s;
    return v;
}

LADEF vec4_f64 vec4_f64_mul(vec4_f64 a, vec4_f64 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
LADEF vec4_f64 vec4_f64_mul_scalar(vec4_f64 v, double s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    v.w *= s;
    return v;
}

LADEF vec4_f64 vec4_f64_div(vec4_f64 a, vec4_f64 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
LADEF vec4_f64 vec4_f64_div_scalar(vec4_f64 v, double s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    v.w /= s;
    return v;
}

LADEF vec4_f64 make_vec4_f64_sqrt(vec4_f64 a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    a.w = sqrt(a.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_pow(vec4_f64 base, vec4_f64 exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    base.w = pow(base.w, exp.w);
    return base;
}

LADEF vec4_f64 make_vec4_f64_sin(vec4_f64 a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    a.w = sin(a.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_cos(vec4_f64 a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    a.w = cos(a.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_min(vec4_f64 a, vec4_f64 b)
{
    a.x = min_f64(a.x, b.x);
    a.y = min_f64(a.y, b.y);
    a.z = min_f64(a.z, b.z);
    a.w = min_f64(a.w, b.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_max(vec4_f64 a, vec4_f64 b)
{
    a.x = max_f64(a.x, b.x);
    a.y = max_f64(a.y, b.y);
    a.z = max_f64(a.z, b.z);
    a.w = max_f64(a.w, b.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_lerp(vec4_f64 a, vec4_f64 b, vec4_f64 t)
{
    a.x = lerp_f64(a.x, b.x, t.x);
    a.y = lerp_f64(a.y, b.y, t.y);
    a.z = lerp_f64(a.z, b.z, t.z);
    a.w = lerp_f64(a.w, b.w, t.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_floor(vec4_f64 a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    a.w = floor(a.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_ceil(vec4_f64 a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    a.w = ceil(a.w);
    return a;
}

LADEF vec4_f64 make_vec4_f64_clamp(vec4_f64 x, vec4_f64 a, vec4_f64 b)
{
    x.x = clamp_f64(x.x, a.x, b.x);
    x.y = clamp_f64(x.y, a.y, b.y);
    x.z = clamp_f64(x.z, a.z, b.z);
    x.w = clamp_f64(x.w, a.w, b.w);
    return x;
}

LADEF double make_vec4_f64_sqrlen(vec4_f64 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF double make_vec4_f64_len(vec4_f64 a)
{
    return sqrtl(make_vec4_f64_sqrlen(a));
}

LADEF vec4_i32 make_vec4_i32(int x, int y, int z, int w)
{
    vec4_i32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF vec4_i32 make_vec4_i32_scalar(int x)
{
    return make_vec4_i32(x, x, x, x);
}

LADEF vec4_i32 v4_i32_to_v2(vec2 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v2_f64(vec2_f64 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v2_i32(vec2_i32 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v2_u32(vec2_u32 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v3(vec3 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v3_f64(vec3_f64 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v3_i32(vec3_i32 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v3_u32(vec3_u32 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}

LADEF vec4_i32 v4_i32_to_v4(vec4 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}

LADEF vec4_i32 v4_i32_to_v4_f64(vec4_f64 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}

LADEF vec4_i32 v4_i32_to_v4_u32(vec4_u32 a)
{
    vec4_i32 result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}

LADEF vec4_i32 vec4_i32_add(vec4_i32 a, vec4_i32 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
LADEF vec4_i32 vec4_i32_add_scalar(vec4_i32 v, int s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    v.w += s;
    return v;
}

LADEF vec4_i32 vec4_i32_sub(vec4_i32 a, vec4_i32 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
LADEF vec4_i32 vec4_i32_sub_scalar(vec4_i32 v, int s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    v.w -= s;
    return v;
}

LADEF vec4_i32 vec4_i32_mul(vec4_i32 a, vec4_i32 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
LADEF vec4_i32 vec4_i32_mul_scalar(vec4_i32 v, int s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    v.w *= s;
    return v;
}

LADEF vec4_i32 vec4_i32_div(vec4_i32 a, vec4_i32 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
LADEF vec4_i32 vec4_i32_div_scalar(vec4_i32 v, int s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    v.w /= s;
    return v;
}

LADEF vec4_i32 make_vec4_i32_min(vec4_i32 a, vec4_i32 b)
{
    a.x = min_i32(a.x, b.x);
    a.y = min_i32(a.y, b.y);
    a.z = min_i32(a.z, b.z);
    a.w = min_i32(a.w, b.w);
    return a;
}

LADEF vec4_i32 make_vec4_i32_max(vec4_i32 a, vec4_i32 b)
{
    a.x = max_i32(a.x, b.x);
    a.y = max_i32(a.y, b.y);
    a.z = max_i32(a.z, b.z);
    a.w = max_i32(a.w, b.w);
    return a;
}

LADEF vec4_i32 make_vec4_i32_clamp(vec4_i32 x, vec4_i32 a, vec4_i32 b)
{
    x.x = clamp_i32(x.x, a.x, b.x);
    x.y = clamp_i32(x.y, a.y, b.y);
    x.z = clamp_i32(x.z, a.z, b.z);
    x.w = clamp_i32(x.w, a.w, b.w);
    return x;
}

LADEF int make_vec4_i32_sqrlen(vec4_i32 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LADEF vec4_u32 make_vec4_u32(unsigned int x, unsigned int y, unsigned int z, unsigned int w)
{
    vec4_u32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF vec4_u32 make_vec4_u32_scalar(unsigned int x)
{
    return make_vec4_u32(x, x, x, x);
}

LADEF vec4_u32 v4_u32_to_v2(vec2 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v2_f64(vec2_f64 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v2_i32(vec2_i32 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v2_u32(vec2_u32 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v3(vec3 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v3_f64(vec3_f64 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v3_i32(vec3_i32 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v3_u32(vec3_u32 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}

LADEF vec4_u32 v4_u32_to_v4(vec4 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}

LADEF vec4_u32 v4_u32_to_v4_f64(vec4_f64 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}

LADEF vec4_u32 v4_u32_to_v4_i32(vec4_i32 a)
{
    vec4_u32 result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}

LADEF vec4_u32 vec4_u32_add(vec4_u32 a, vec4_u32 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}
LADEF vec4_u32 vec4_u32_add_scalar(vec4_u32 v, unsigned int s)
{
    v.x += s;
    v.y += s;
    v.z += s;
    v.w += s;
    return v;
}

LADEF vec4_u32 vec4_u32_sub(vec4_u32 a, vec4_u32 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}
LADEF vec4_u32 vec4_u32_sub_scalar(vec4_u32 v, unsigned int s)
{
    v.x -= s;
    v.y -= s;
    v.z -= s;
    v.w -= s;
    return v;
}

LADEF vec4_u32 vec4_u32_mul(vec4_u32 a, vec4_u32 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}
LADEF vec4_u32 vec4_u32_mul_scalar(vec4_u32 v, unsigned int s)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    v.w *= s;
    return v;
}

LADEF vec4_u32 vec4_u32_div(vec4_u32 a, vec4_u32 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}
LADEF vec4_u32 vec4_u32_div_scalar(vec4_u32 v, unsigned int s)
{
    v.x /= s;
    v.y /= s;
    v.z /= s;
    v.w /= s;
    return v;
}

LADEF vec4_u32 make_vec4_u32_min(vec4_u32 a, vec4_u32 b)
{
    a.x = min_u32(a.x, b.x);
    a.y = min_u32(a.y, b.y);
    a.z = min_u32(a.z, b.z);
    a.w = min_u32(a.w, b.w);
    return a;
}

LADEF vec4_u32 make_vec4_u32_max(vec4_u32 a, vec4_u32 b)
{
    a.x = max_u32(a.x, b.x);
    a.y = max_u32(a.y, b.y);
    a.z = max_u32(a.z, b.z);
    a.w = max_u32(a.w, b.w);
    return a;
}

LADEF vec4_u32 make_vec4_u32_clamp(vec4_u32 x, vec4_u32 a, vec4_u32 b)
{
    x.x = clamp_u32(x.x, a.x, b.x);
    x.y = clamp_u32(x.y, a.y, b.y);
    x.z = clamp_u32(x.z, a.z, b.z);
    x.w = clamp_u32(x.w, a.w, b.w);
    return x;
}

LADEF unsigned int make_vec4_u32_sqrlen(vec4_u32 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

