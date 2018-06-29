/*******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-present Lars Schütz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#ifndef CGM_H_INCLUDE
#define CGM_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef CGM_STATIC
#define CGM_LINKAGE static
#else
#define CGM_LINKAGE
#endif // CGM_STATIC

#define CGM_ALMOST_ZERO 10e-7f
#define CGM_ONE_DEG_IN_RAD 0.017453f
#define CGM_ONE_RAD_IN_DEG 57.295779f
#define CGM_PI 3.141592f
#define CGM_2_PI 6.283184f

#ifdef _WIN32
#ifdef far
#undef far
#endif // far
#ifdef near
#undef near
#endif // near
#endif // _WIN32

typedef struct vec2 {
    float x;
    float y;
} vec2;

typedef struct vec3 {
    float x;
    float y;
    float z;
} vec3;

typedef struct vec4 {
    float x;
    float y;
    float z;
    float w;
} vec4;

// Stored in column-major order
typedef struct mat4 {
    float m[16];
} mat4;

// -----------------------------------------------------------------------------
// Vector functions
// -----------------------------------------------------------------------------
// Constructors
CGM_LINKAGE vec2 vec2_2f(float x, float y);
CGM_LINKAGE vec2 vec2_vec2(vec2 v);
CGM_LINKAGE vec2 vec2_vec3(vec3 v);
CGM_LINKAGE vec2 vec2_vec4(vec4 v);

CGM_LINKAGE vec3 vec3_3f(float x, float y, float z);
CGM_LINKAGE vec3 vec3_vec2_f(vec2 v, float z);
CGM_LINKAGE vec3 vec3_vec3(vec3 v);
CGM_LINKAGE vec3 vec3_vec4(vec4 v);

CGM_LINKAGE vec4 vec4_4f(float x, float y, float z, float w);
CGM_LINKAGE vec4 vec4_vec2_2f(vec2 v, float z, float w);
CGM_LINKAGE vec4 vec4_vec3_f(vec3 v, float w);
CGM_LINKAGE vec4 vec4_vec4(vec4 v);

// Basic mathematical operators
CGM_LINKAGE vec2 vec2_add_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_add_vec2(vec2 v1, vec2 v2);
CGM_LINKAGE vec2 vec2_div_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_div_vec2(vec2 v1, vec2 v2);
CGM_LINKAGE vec2 vec2_mul_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_mul_vec2(vec2 v1, vec2 v2);
CGM_LINKAGE vec2 vec2_sub_f(vec2 v, float s);
CGM_LINKAGE vec2 vec2_sub_vec2(vec2 v1, vec2 v2);

CGM_LINKAGE vec3 vec3_add_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_add_vec3(vec3 v1, vec3 v2);
CGM_LINKAGE vec3 vec3_div_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_div_vec3(vec3 v1, vec3 v2);
CGM_LINKAGE vec3 vec3_mul_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_mul_vec3(vec3 v1, vec3 v2);
CGM_LINKAGE vec3 vec3_sub_f(vec3 v, float s);
CGM_LINKAGE vec3 vec3_sub_vec3(vec3 v1, vec3 v2);

CGM_LINKAGE vec4 vec4_add_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_add_vec4(vec4 v1, vec4 v2);
CGM_LINKAGE vec4 vec4_div_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_div_vec4(vec4 v1, vec4 v2);
CGM_LINKAGE vec4 vec4_mul_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_mul_vec4(vec4 v1, vec4 v2);
CGM_LINKAGE vec4 vec4_sub_f(vec4 v, float s);
CGM_LINKAGE vec4 vec4_sub_vec4(vec4 v1, vec4 v2);

// Vector specific operators
CGM_LINKAGE float vec2_dot_vec2(vec2 v1, vec2 v2);
CGM_LINKAGE float vec2_length(vec2 v);
CGM_LINKAGE float vec2_sq_length(vec2 v);
CGM_LINKAGE vec2 vec2_normalize(vec2 v);

CGM_LINKAGE vec3 vec3_cross_vec3(vec3 v1, vec3 v2);
CGM_LINKAGE float vec3_dot_vec3(vec3 v1, vec3 v2);
CGM_LINKAGE float vec3_length(vec3 v);
CGM_LINKAGE float vec3_sq_length(vec3 v);
CGM_LINKAGE vec3 vec3_normalize(vec3 v);

CGM_LINKAGE vec4 vec4_cross_vec4(vec4 v1, vec4 v2);
CGM_LINKAGE float vec4_dot_vec4(vec4 v1, vec4 v2);
CGM_LINKAGE float vec4_length(vec4 v);
CGM_LINKAGE float vec4_sq_length(vec4 v);
CGM_LINKAGE vec4 vec4_normalize(vec4 v);

// Output
CGM_LINKAGE void vec2_print(vec2 v);
CGM_LINKAGE void vec3_print(vec3 v);
CGM_LINKAGE void vec4_print(vec4 v);

// -----------------------------------------------------------------------------
// Matrix functions
// -----------------------------------------------------------------------------
// Constructors
CGM_LINKAGE mat4 mat4_identity();
CGM_LINKAGE mat4 mat4_zero();
CGM_LINKAGE mat4 mat4_mat4(mat4 m);

// Value access
CGM_LINKAGE vec4 mat4_col(mat4 m, int col);
CGM_LINKAGE vec4 mat4_row(mat4 m, int row);
CGM_LINKAGE float mat4_entry(mat4 m, int col, int row);

// Basic mathematical operators
CGM_LINKAGE mat4 mat4_add_mat4(mat4 m1, mat4 m2);
CGM_LINKAGE mat4 mat4_div_f(mat4 m, float s);
CGM_LINKAGE mat4 mat4_mul_f(mat4 m, float s);
CGM_LINKAGE mat4 mat4_mul_mat4(mat4 m1, mat4 m2);
CGM_LINKAGE vec4 mat4_mul_vec4(mat4 m, vec4 v);
CGM_LINKAGE mat4 mat4_sub_mat4(mat4 m1, mat4 m2);

// Matrix specific operators
CGM_LINKAGE float mat4_determinant(mat4 m);
CGM_LINKAGE mat4 mat4_invert(mat4 m);
CGM_LINKAGE mat4 mat4_transpose(mat4 m);

// Transformation operators
CGM_LINKAGE mat4 mat4_rotate(vec3 axis, float rad);
CGM_LINKAGE mat4 mat4_rotate_x(float rad);
CGM_LINKAGE mat4 mat4_rotate_y(float rad);
CGM_LINKAGE mat4 mat4_rotate_z(float rad);
CGM_LINKAGE mat4 mat4_scale(vec3 v);
CGM_LINKAGE mat4 mat4_translate(vec3 v);

// Virtual camera functions
CGM_LINKAGE mat4 mat4_frustum(float left, float right, float bottom, float top,
                            float near, float far);
CGM_LINKAGE mat4 mat4_look_at(vec3 eye, vec3 center, vec3 up);
CGM_LINKAGE mat4 mat4_ortho(float left, float right, float bottom, float top,
                        float near, float far);
CGM_LINKAGE mat4 mat4_perspective(float fovy, float aspect, float near,
                            float far);

// Output
CGM_LINKAGE void mat4_print(mat4 m);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CGM_H_INCLUDE

#ifdef CGM_IMPLEMENTATION
#undef CGM_IMPLEMENTATION

#include <math.h>
#include <stdio.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Vector functions
// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_2f(float x, float y)
{
    vec2 r;
    r.x = x;
    r.y = y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_vec2(vec2 v)
{
    vec2 r;
    r.x = v.x;
    r.y = v.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_vec3(vec3 v)
{
    vec2 r;
    r.x = v.x;
    r.y = v.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_vec4(vec4 v)
{
    vec2 r;
    r.x = v.x;
    r.y = v.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_3f(float x, float y, float z)
{
    vec3 r;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_vec2_f(vec2 v, float z)
{
    vec3 r;
    r.x = v.x;
    r.y = v.y;
    r.z = z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_vec3(vec3 v)
{
    vec3 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_vec4(vec4 v)
{
    vec3 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_4f(float x, float y, float z, float w)
{
    vec4 r;
    r.x = x;
    r.y = y;
    r.z = z;
    r.w = w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_vec2_2f(vec2 v, float z, float w)
{
    vec4 r;
    r.x = v.x;
    r.y = v.y;
    r.z = z;
    r.w = w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_vec3_f(vec3 v, float w)
{
    vec4 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_vec4(vec4 v)
{
    vec4 r;
    r.x = v.x;
    r.y = v.y;
    r.z = v.z;
    r.w = v.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_add_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x + s;
    r.y = v.y + s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_add_vec2(vec2 v1, vec2 v2)
{
    vec2 r;
    r.x = v1.x + v2.x;
    r.y = v1.y + v2.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_div_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x / s;
    r.y = v.y / s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_div_vec2(vec2 v1, vec2 v2)
{
    vec2 r;
    r.x = v1.x / v2.x;
    r.y = v1.y / v2.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_mul_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_mul_vec2(vec2 v1, vec2 v2)
{
    vec2 r;
    r.x = v1.x * v2.x;
    r.y = v1.y * v2.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_sub_f(vec2 v, float s)
{
    vec2 r;
    r.x = v.x - s;
    r.y = v.y - s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_sub_vec2(vec2 v1, vec2 v2)
{
    vec2 r;
    r.x = v1.x - v2.x;
    r.y = v1.y - v2.y;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_add_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x + s;
    r.y = v.y + s;
    r.z = v.z + s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_add_vec3(vec3 v1, vec3 v2)
{
    vec3 r;
    r.x = v1.x + v2.x;
    r.y = v1.y + v2.y;
    r.z = v1.z + v2.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_div_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x / s;
    r.y = v.y / s;
    r.z = v.z / s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_div_vec3(vec3 v1, vec3 v2)
{
    vec3 r;
    r.x = v1.x / v2.x;
    r.y = v1.y / v2.y;
    r.z = v1.z / v2.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_mul_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_mul_vec3(vec3 v1, vec3 v2)
{
    vec3 r;
    r.x = v1.x * v2.x;
    r.y = v1.y * v2.y;
    r.z = v1.z * v2.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_sub_f(vec3 v, float s)
{
    vec3 r;
    r.x = v.x - s;
    r.y = v.y - s;
    r.z = v.z - s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_sub_vec3(vec3 v1, vec3 v2)
{
    vec3 r;
    r.x = v1.x - v2.x;
    r.y = v1.y - v2.y;
    r.z = v1.z - v2.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_add_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x + s;
    r.y = v.y + s;
    r.z = v.z + s;
    r.w = v.w + s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_add_vec4(vec4 v1, vec4 v2)
{
    vec4 r;
    r.x = v1.x + v2.x;
    r.y = v1.y + v2.y;
    r.z = v1.z + v2.z;
    r.w = v1.w + v2.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_mul_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    r.w = v.w * s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_mul_vec4(vec4 v1, vec4 v2)
{
    vec4 r;
    r.x = v1.x * v2.x;
    r.y = v1.y * v2.y;
    r.z = v1.z * v2.z;
    r.w = v1.w * v2.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_div_vec4(vec4 v1, vec4 v2)
{
    vec4 r;
    r.x = v1.x / v2.x;
    r.y = v1.y / v2.y;
    r.z = v1.z / v2.z;
    r.w = v1.w / v2.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_div_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x / s;
    r.y = v.y / s;
    r.z = v.z / s;
    r.w = v.w / s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_sub_f(vec4 v, float s)
{
    vec4 r;
    r.x = v.x - s;
    r.y = v.y - s;
    r.z = v.z - s;
    r.w = v.w - s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_sub_vec4(vec4 v1, vec4 v2)
{
    vec4 r;
    r.x = v1.x - v2.x;
    r.y = v1.y - v2.y;
    r.z = v1.z - v2.z;
    r.w = v1.w - v2.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec2_dot_vec2(vec2 v1, vec2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec2_length(vec2 v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec2_sq_length(vec2 v)
{
    return v.x * v.x + v.y * v.y;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec2 vec2_normalize(vec2 v)
{
    vec2 r;
    float length = vec2_length(v);
    if (length < CGM_ALMOST_ZERO) {
        return vec2_2f(0.0f, 0.0f);
    }
    r.x = v.x / length;
    r.y = v.y / length;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_cross_vec3(vec3 v1, vec3 v2)
{
    float x = v1.y * v2.z - v1.z * v2.y;
    float y = v1.z * v2.x - v1.x * v2.z;
    float z = v1.x * v2.y - v1.y * v2.x;
    return vec3_3f(x, y, z);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec3_dot_vec3(vec3 v1, vec3 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec3_length(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec3_sq_length(vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec3 vec3_normalize(vec3 v)
{
    vec3 r;
    float length = vec3_length(v);
    if (length < CGM_ALMOST_ZERO) {
        return vec3_3f(0.0f, 0.0f, 0.0f);
    }
    r.x = v.x / length;
    r.y = v.y / length;
    r.z = v.z / length;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_cross_vec4(vec4 v1, vec4 v2)
{
    float x = v1.y * v2.z - v1.z * v2.y;
    float y = v1.z * v2.x - v1.x * v2.z;
    float z = v1.x * v2.y - v1.y * v2.x;
    return vec4_4f(x, y, z, 1.0f);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec4_dot_vec4(vec4 v1, vec4 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec4_length(vec4 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float vec4_sq_length(vec4 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 vec4_normalize(vec4 v)
{
    vec4 r;
    float length = vec4_length(v);
    if (length < CGM_ALMOST_ZERO) {
        return vec4_4f(0.0f, 0.0f, 0.0f, 0.0f);
    }
    r.x = v.x / length;
    r.y = v.y / length;
    r.z = v.z / length;
    r.w = v.w / length;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void vec2_print(vec2 v)
{
    printf("(%.4f, %.4f)'", v.x, v.y);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void vec3_print(vec3 v)
{
    printf("(%.4f, %.4f, %.4f)'", v.x, v.y, v.z);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void vec4_print(vec4 v)
{
    printf("(%.4f, %.4f, %.4f, %.4f)'", v.x, v.y, v.z, v.w);
}

// -----------------------------------------------------------------------------
// Matrix functions
// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_identity()
{
    mat4 r = mat4_zero();
    r.m[0] = 1.0f;
    r.m[5] = 1.0f;
    r.m[10] = 1.0f;
    r.m[15] = 1.0f;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_zero(){
    mat4 r;
    memset(r.m, 0, 16 * sizeof(float));
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_mat4(mat4 m)
{
    mat4 r;
    memcpy(r.m, m.m, 16 * sizeof(float));
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 mat4_col(mat4 m, int col)
{
    vec4 r;
    r.x = m.m[4 * col];
    r.y = m.m[1 + 4 * col];
    r.z = m.m[2 + 4 * col];
    r.w = m.m[3 + 4 * col];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 mat4_row(mat4 m, int row)
{
    vec4 r;
    r.x = m.m[row];
    r.y = m.m[row + 4];
    r.z = m.m[row + 8];
    r.w = m.m[row + 12];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float mat4_entry(mat4 m, int col, int row)
{
    return m.m[row + 4 * col];
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_add_mat4(mat4 m1, mat4 m2)
{
    mat4 r = mat4_mat4(m1);
    r.m[0] += m2.m[0];
    r.m[1] += m2.m[1];
    r.m[2] += m2.m[2];
    r.m[3] += m2.m[3];
    r.m[4] += m2.m[4];
    r.m[5] += m2.m[5];
    r.m[6] += m2.m[6];
    r.m[7] += m2.m[7];
    r.m[8] += m2.m[8];
    r.m[9] += m2.m[9];
    r.m[10] += m2.m[10];
    r.m[11] += m2.m[11];
    r.m[12] += m2.m[12];
    r.m[13] += m2.m[13];
    r.m[14] += m2.m[14];
    r.m[15] += m2.m[15];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_div_f(mat4 m, float s)
{
    mat4 r = mat4_mat4(m);
    r.m[0] /= s;
    r.m[1] /= s;
    r.m[2] /= s;
    r.m[3] /= s;
    r.m[4] /= s;
    r.m[5] /= s;
    r.m[6] /= s;
    r.m[7] /= s;
    r.m[8] /= s;
    r.m[9] /= s;
    r.m[10] /= s;
    r.m[11] /= s;
    r.m[12] /= s;
    r.m[13] /= s;
    r.m[14] /= s;
    r.m[15] /= s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_mul_f(mat4 m, float s)
{
    mat4 r = mat4_mat4(m);
    r.m[0] *= s;
    r.m[1] *= s;
    r.m[2] *= s;
    r.m[3] *= s;
    r.m[4] *= s;
    r.m[5] *= s;
    r.m[6] *= s;
    r.m[7] *= s;
    r.m[8] *= s;
    r.m[9] *= s;
    r.m[10] *= s;
    r.m[11] *= s;
    r.m[12] *= s;
    r.m[13] *= s;
    r.m[14] *= s;
    r.m[15] *= s;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_mul_mat4(mat4 m1, mat4 m2)
{
    mat4 r;
    int r_entry_pos = 0;
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            float sum = 0.0f;
            for (int i = 0; i < 4; i++) {
                sum += m2.m[i + 4 * col] * m1.m[row + 4 * i];
            }
            r.m[r_entry_pos] = sum;
            r_entry_pos++;
        }
    }
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE vec4 mat4_mul_vec4(mat4 m, vec4 v)
{
    vec4 r;
    r.x = m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z + m.m[12] * v.w;
    r.y = m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z + m.m[13] * v.w;
    r.z = m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z + m.m[14] * v.w;
    r.w = m.m[3] * v.x + m.m[7] * v.y + m.m[11] * v.z + m.m[15] * v.w;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_sub_mat4(mat4 m1, mat4 m2)
{
    mat4 r = mat4_mat4(m1);
    r.m[0] -= m2.m[0];
    r.m[1] -= m2.m[1];
    r.m[2] -= m2.m[2];
    r.m[3] -= m2.m[3];
    r.m[4] -= m2.m[4];
    r.m[5] -= m2.m[5];
    r.m[6] -= m2.m[6];
    r.m[7] -= m2.m[7];
    r.m[8] -= m2.m[8];
    r.m[9] -= m2.m[9];
    r.m[10] -= m2.m[10];
    r.m[11] -= m2.m[11];
    r.m[12] -= m2.m[12];
    r.m[13] -= m2.m[13];
    r.m[14] -= m2.m[14];
    r.m[15] -= m2.m[15];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE float mat4_determinant(mat4 m)
{
    /*
    00 04 08 12
    01 05 09 13
    02 06 10 14
    03 07 11 15
    */
    return
        m.m[0] * m.m[5] * m.m[10] * m.m[15] +
        m.m[0] * m.m[9] * m.m[14] * m.m[7] +
        m.m[0] * m.m[13] * m.m[6] * m.m[11] -
        m.m[0] * m.m[13] * m.m[10] * m.m[7] -
        m.m[0] * m.m[9] * m.m[6] * m.m[15] -
        m.m[0] * m.m[5] * m.m[14] * m.m[11] -
        m.m[4] * m.m[9] * m.m[14] * m.m[3] -
        m.m[4] * m.m[13] * m.m[2] * m.m[11] -
        m.m[4] * m.m[1] * m.m[10] * m.m[15] +
        m.m[4] * m.m[1] * m.m[14] * m.m[11] +
        m.m[4] * m.m[13] * m.m[10] * m.m[3] +
        m.m[4] * m.m[9] * m.m[2] * m.m[15] +
        m.m[8] * m.m[13] * m.m[2] * m.m[7] +
        m.m[8] * m.m[1] * m.m[6] * m.m[15] +
        m.m[8] * m.m[5] * m.m[14] * m.m[3] -
        m.m[8] * m.m[5] * m.m[2] * m.m[15] -
        m.m[8] * m.m[1] * m.m[14] * m.m[7] -
        m.m[8] * m.m[13] * m.m[6] * m.m[3] -
        m.m[12] * m.m[1] * m.m[6] * m.m[11] -
        m.m[12] * m.m[5] * m.m[10] * m.m[3] -
        m.m[12] * m.m[9] * m.m[2] * m.m[7] +
        m.m[12] * m.m[9] * m.m[6] * m.m[3] +
        m.m[12] * m.m[5] * m.m[2] * m.m[11] +
        m.m[12] * m.m[1] * m.m[10] * m.m[7];
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_invert(mat4 m)
{
    float det = mat4_determinant(m);
    if (fabsf(det) < CGM_ALMOST_ZERO) {
        return m;
    }

    /*
    00 04 08 12
    01 05 09 13
    02 06 10 14
    03 07 11 15
    */
    mat4 r;
    r.m[0] =
        m.m[9] * m.m[14] * m.m[7] - m.m[13] * m.m[10] * m.m[7] +
        m.m[13] * m.m[6] * m.m[11] - m.m[5] * m.m[14] * m.m[11] -
        m.m[9] * m.m[6] * m.m[15] + m.m[5] * m.m[10] * m.m[15];
    r.m[1] =
        m.m[13] * m.m[10] * m.m[3] - m.m[9] * m.m[14] * m.m[3] -
        m.m[13] * m.m[2] * m.m[11] + m.m[1] * m.m[14] * m.m[11] +
        m.m[9] * m.m[2] * m.m[15] - m.m[1] * m.m[10] * m.m[15];
    r.m[2] =
        m.m[5] * m.m[14] * m.m[3] - m.m[13] * m.m[6] * m.m[3] +
        m.m[13] * m.m[2] * m.m[7] - m.m[1] * m.m[14] * m.m[7] -
        m.m[5] * m.m[2] * m.m[15] + m.m[1] * m.m[6] * m.m[15];
    r.m[3] =
        m.m[9] * m.m[6] * m.m[3] - m.m[5] * m.m[10] * m.m[3] -
        m.m[9] * m.m[2] * m.m[7] + m.m[1] * m.m[10] * m.m[7] +
        m.m[5] * m.m[2] * m.m[11] - m.m[1] * m.m[6] * m.m[11];
    r.m[4] =
        m.m[12] * m.m[10] * m.m[7] - m.m[8] * m.m[14] * m.m[7] -
        m.m[12] * m.m[6] * m.m[11] + m.m[4] * m.m[14] * m.m[11] +
        m.m[8] * m.m[6] * m.m[15] - m.m[4] * m.m[10] * m.m[15];
    r.m[5] =
        m.m[8] * m.m[14] * m.m[3] - m.m[12] * m.m[10] * m.m[3] +
        m.m[12] * m.m[2] * m.m[11] - m.m[0] * m.m[14] * m.m[11] -
        m.m[8] * m.m[2] * m.m[15] + m.m[0] * m.m[10] * m.m[15];
    r.m[6] =
        m.m[12] * m.m[6] * m.m[3] - m.m[4] * m.m[14] * m.m[3] -
        m.m[12] * m.m[2] * m.m[7] + m.m[0] * m.m[14] * m.m[7] +
        m.m[4] * m.m[2] * m.m[15] - m.m[0] * m.m[6] * m.m[15];
    r.m[7] =
        m.m[4] * m.m[10] * m.m[3] - m.m[8] * m.m[6] * m.m[3] +
        m.m[8] * m.m[2] * m.m[7] - m.m[0] * m.m[10] * m.m[7] -
        m.m[4] * m.m[2] * m.m[11] + m.m[0] * m.m[6] * m.m[11];
    r.m[8] =
        m.m[8] * m.m[13] * m.m[7] - m.m[12] * m.m[9] * m.m[7] +
        m.m[12] * m.m[5] * m.m[11] - m.m[4] * m.m[13] * m.m[11] -
        m.m[8] * m.m[5] * m.m[15] + m.m[4] * m.m[9] * m.m[15];
    r.m[9] =
        m.m[12] * m.m[9] * m.m[3] - m.m[8] * m.m[13] * m.m[3] -
        m.m[12] * m.m[1] * m.m[11] + m.m[0] * m.m[13] * m.m[11] +
        m.m[8] * m.m[1] * m.m[15] - m.m[0] * m.m[9] * m.m[15];
    r.m[10] =
        m.m[4] * m.m[13] * m.m[3] - m.m[12] * m.m[5] * m.m[3] +
        m.m[12] * m.m[1] * m.m[7] - m.m[0] * m.m[13] * m.m[7] -
        m.m[4] * m.m[1] * m.m[15] + m.m[0] * m.m[5] * m.m[15];
    r.m[11] =
        m.m[8] * m.m[5] * m.m[3] - m.m[4] * m.m[9] * m.m[3] -
        m.m[8] * m.m[1] * m.m[7] + m.m[0] * m.m[9] * m.m[7] +
        m.m[4] * m.m[1] * m.m[11] - m.m[0] * m.m[5] * m.m[11];
    r.m[12] =
        m.m[12] * m.m[9] * m.m[6] - m.m[8] * m.m[13] * m.m[6] -
        m.m[12] * m.m[5] * m.m[10] + m.m[4] * m.m[13] * m.m[10] +
        m.m[8] * m.m[5] * m.m[14] - m.m[4] * m.m[9] * m.m[14];
    r.m[13] =
        m.m[8] * m.m[13] * m.m[2] - m.m[12] * m.m[9] * m.m[2] +
        m.m[12] * m.m[1] * m.m[10] - m.m[0] * m.m[13] * m.m[10] -
        m.m[8] * m.m[1] * m.m[14] + m.m[0] * m.m[9] * m.m[14];
    r.m[14] =
        m.m[12] * m.m[5] * m.m[2] - m.m[4] * m.m[13] * m.m[2] -
        m.m[12] * m.m[1] * m.m[6] + m.m[0] * m.m[13] * m.m[6] +
        m.m[4] * m.m[1] * m.m[14] - m.m[0] * m.m[5] * m.m[14];
    r.m[15] =
        m.m[4] * m.m[9] * m.m[2] - m.m[8] * m.m[5] * m.m[2] +
        m.m[8] * m.m[1] * m.m[6] - m.m[0] * m.m[9] * m.m[6] -
        m.m[4] * m.m[1] * m.m[10] + m.m[0] * m.m[5] * m.m[10];

    return mat4_mul_f(r, 1.0f / det);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_transpose(mat4 m)
{
    mat4 r;
    r.m[0] = m.m[0];
    r.m[1] = m.m[4];
    r.m[2] = m.m[8];
    r.m[3] = m.m[12];
    r.m[4] = m.m[1];
    r.m[5] = m.m[5];
    r.m[6] = m.m[9];
    r.m[7] = m.m[13];
    r.m[8] = m.m[2];
    r.m[9] = m.m[6];
    r.m[10] = m.m[10];
    r.m[11] = m.m[14];
    r.m[12] = m.m[3];
    r.m[13] = m.m[7];
    r.m[14] = m.m[11];
    r.m[15] = m.m[15];
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate(vec3 axis, float rad)
{
    if (vec3_length(axis) != 1.0f) {
        axis = vec3_normalize(axis);
    }
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    // Rodrigues rotation formula
    float c = cosf(rad);
    float s = sinf(rad);
    float tmp = sinf(rad / 2.0f);
    float t = 2.0f * tmp * tmp; // 1.0f - cosf(rad);
    mat4 r;
    r.m[0] = t * x * x + c;
    r.m[1] = t * x * y + s * z;
    r.m[2] = t * x * z - s * y;
    r.m[3] = 0.0f;
    r.m[4] = t * x * y - s * z;
    r.m[5] = t * y * y + c;
    r.m[6] = t * y * z + s * x;
    r.m[7] = 0.0f;
    r.m[8] = t * x * z + s * y;
    r.m[9] = t * y * z - s * x;
    r.m[10] = t * z * z + c;
    r.m[11] = 0.0f;
    r.m[12] = 0.0f;
    r.m[13] = 0.0f;
    r.m[14] = 0.0f;
    r.m[15] = 1.0f;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate_x(float rad)
{
    mat4 r = mat4_identity();
    r.m[5] = cosf(rad);
    r.m[6] = sinf(rad);
    r.m[9] = -sinf(rad);
    r.m[10] = cosf(rad);
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate_y(float rad)
{
    mat4 r = mat4_identity();
    r.m[0] = cosf(rad);
    r.m[2] = -sinf(rad);
    r.m[8] = sinf(rad);
    r.m[10] = cosf(rad);
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_rotate_z(float rad)
{
    mat4 r = mat4_identity();
    r.m[0] = cosf(rad);
    r.m[1] = sinf(rad);
    r.m[4] = -sinf(rad);
    r.m[5] = cosf(rad);
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_scale(vec3 v)
{
    mat4 r = mat4_identity();
    r.m[0] = v.x;
    r.m[5] = v.y;
    r.m[10] = v.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_translate(vec3 v)
{
    mat4 r = mat4_identity();
    r.m[12] = v.x;
    r.m[13] = v.y;
    r.m[14] = v.z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_frustum(float left, float right, float bottom, float top,
                            float near, float far)
{
    mat4 r = mat4_zero();
    r.m[0] = 2.0f * near / (right - left);
    r.m[5] = 2.0f * near / (top - bottom);
    r.m[8] = (right + left) / (right - left);
    r.m[9] = (top + bottom) / (top - bottom);
    r.m[10] = -(far + near) / (far - near);
    r.m[11] = -1.0f;
    r.m[14] = -2.0f * (far * near) / (far - near);
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_look_at(vec3 eye, vec3 center, vec3 up)
{
    vec3 F = vec3_sub_vec3(center, eye);
    vec3 f = vec3_normalize(F);
    vec3 up_normalized = vec3_normalize(up);
    vec3 s = vec3_cross_vec3(f, up_normalized);
    vec3 s_normalized = vec3_normalize(s);
    vec3 u = vec3_cross_vec3(s_normalized, f);

    mat4 m = mat4_zero();
    m.m[0] = s.x;
    m.m[1] = u.x;
    m.m[2] = -f.x;
    m.m[4] = s.y;
    m.m[5] = u.y;
    m.m[6] = -f.y;
    m.m[8] = s.z;
    m.m[9] = u.z;
    m.m[10] = -f.z;
    m.m[15] = 1.0f;
    mat4 translation = mat4_translate(vec3_3f(-eye.x, -eye.y, -eye.z));
    return mat4_mul_mat4(translation, m);
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_ortho(float left, float right, float bottom, float top,
                        float near, float far)
{
    mat4 r = mat4_zero();
    r.m[0] = 2.0f / (right - left);
    r.m[5] = 2.0f / (top - bottom);
    r.m[10] = -2.0f / (far - near);
    r.m[12] = -(right + left) / (right - left);
    r.m[13] = -(top + bottom) / (top - bottom);
    r.m[14] = -(far + near) / (far - near);
    r.m[15] = 1.0f;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE mat4 mat4_perspective(float fovy, float aspect, float near,
                                float far)
{
    float fovy_rad = CGM_ONE_DEG_IN_RAD * fovy;
    float range = tanf(fovy_rad / 2.0f) * near;
    float s_x = (2.0f * near) / (range * aspect + range * aspect);
    float s_y = near / range;
    float s_z = -(far + near) / (far - near);
    float p_z = -(2.0f * far * near) / (far - near);

    mat4 r = mat4_zero();
    r.m[0] = s_x;
    r.m[5] = s_y;
    r.m[10] = s_z;
    r.m[11] = -1.0f;
    r.m[14] = p_z;
    return r;
}

// -----------------------------------------------------------------------------
CGM_LINKAGE void mat4_print(mat4 m)
{
    printf("(%.4f %.4f %.4f %.4f)\n", m.m[0], m.m[4], m.m[8], m.m[12]);
    printf("(%.4f %.4f %.4f %.4f)\n", m.m[1], m.m[5], m.m[9], m.m[13]);
    printf("(%.4f %.4f %.4f %.4f)\n", m.m[2], m.m[6], m.m[10], m.m[14]);
    printf("(%.4f %.4f %.4f %.4f)", m.m[3], m.m[7], m.m[11], m.m[15]);
}

#endif // CGM_IMPLEMENTATION
