#include <math.h>
#include "vec2.h"

float vec2_length(vec2 v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

vec2 vec2_add(vec2 a, vec2 b) {
	return (vec2){ a.x + b.x, a.y + b.y };
}

vec2 vec2_sub(vec2 a, vec2 b) {
	return (vec2){ a.x - b.x, a.y - b.y };
}

vec2 vec2_mul(vec2 v, float scale) {
	return (vec2){ v.x * scale, v.y * scale };
}

vec2 vec2_div(vec2 v, float scale) {
	return (vec2){ v.x / scale, v.y / scale };
}

float vec2_dot(vec2 a, vec2 b) {
	return a.x * b.x + a.y * b.y;
}
