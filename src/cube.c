#include "vec3.h"
#include "cube.h"

vec3 cube_vertices[CUBE_VERTICES] = {
	{ -1, -1,  0 },
	{  1, -1,  0 },
	{  1,  1,  0 },
	{ -1,  1,  0 },
	{ -1,  1, -1 },
	{ -1, -1, -1 },
	{  1, -1, -1 },
	{  1,  1, -1 }
};

// TODO: implement face struct
// vec3 cube_faces[CUBE_FACES] = {
// 	// front
//     { .a = 1, .b = 2, .c = 3 },
//     { .a = 1, .b = 3, .c = 4 },
//     // right
//     { .a = 4, .b = 3, .c = 5 },
//     { .a = 4, .b = 5, .c = 6 },
//     // back
//     { .a = 6, .b = 5, .c = 7 },
//     { .a = 6, .b = 7, .c = 8 },
//     // left
//     { .a = 8, .b = 7, .c = 2 },
//     { .a = 8, .b = 2, .c = 1 },
//     // top
//     { .a = 2, .b = 7, .c = 5 },
//     { .a = 2, .b = 5, .c = 3 },
//     // bottom
//     { .a = 6, .b = 8, .c = 1 },
//     { .a = 6, .b = 1, .c = 4 }
// };
