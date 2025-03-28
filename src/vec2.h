#ifndef VEC2_H
#define VEC2_H

typedef struct {
	float x;
	float y;
} vec2;

float vec2_length(vec2 v);
vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_mul(vec2 v, float scale);
vec2 vec2_div(vec2 v, float scale);
vec2 vec2_cross(vec2 a, vec2 b);
float vec2_dot(vec2 a, vec2 b);

#endif
