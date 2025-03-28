#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
	float m[4][4];
} mat4;

mat4 mat4_identity(void);
mat4 mat4_scale(float sx, float sy, float sz);
mat4 mat4_rotate(void);
mat4 mat4_translate(void);

#endif
