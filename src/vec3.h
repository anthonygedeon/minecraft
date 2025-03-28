#ifndef VEC3_H
#define VEC3_H

typedef struct {
	float x;
	float y; 
	float z;
} vec3;

float vec3_length(vec3 v);
vec3 vec3_normalize(vec3 v);

vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);
vec3 vec3_mul(vec3 v, float scale);
vec3 vec3_div(vec3 v, float scale);

vec3 vec3_cross(vec3 a, vec3 b);
float vec3_dot(vec3 a, vec3 b);

#endif

