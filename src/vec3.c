#include "vec3.h"
#include <math.h>

vec3 vec3_add(vec3 a, vec3 b) {
	return (vec3){ a.x + b.x, a.y + b.y, a.z + b.z };
}

vec3 vec3_sub(vec3 a, vec3 b) {
	return (vec3){ a.x - b.x, a.y - b.y, a.z - b.z };
}

float vec3_length(vec3 v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3 vec3_mul(vec3 v, float scale) {
	return (vec3){ v.x * scale, v.y * scale, v.z * scale };
}

vec3 vec3_div(vec3 v, float scale) {
	return (vec3){ v.x / scale, v.y / scale, v.z / scale };
}

vec3 vec3_normalize(vec3 v) {
	vec3 normal;
	normal.x = v.x / vec3_length(v);
    normal.y = v.y / vec3_length(v);
    normal.z = v.z / vec3_length(v);	
	return normal;
}

vec3 vec3_cross(vec3 a, vec3 b) {
	float nx = a.y * b.z - a.z * b.y;
	float ny = a.z * b.x - a.x * b.z;
	float nz = a.x * b.y - a.y * b.x;
	return (vec3) { nx, ny, nz };
}

float vec3_dot(vec3 a, vec3 b) {
	return a.x * b.x + a.y * b.y  + a.z * b.z;
}
