#ifndef MESH_H
#define MESH_H

#include "vec3.h"

typedef struct {
	vec3 scale;
	vec3 rotate;
	vec3 translate;
} Transform;

typedef struct {
	int  faces;
	vec3* vertices;
	Transform transform;
} Mesh;

Mesh mesh_create(void);

#endif
