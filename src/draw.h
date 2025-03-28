#ifndef DRAW_H
#define DRAW_H

#include "types.h"
#include "window.h"
#include "vec2.h"

typedef struct {
	u32 color_buffer[WIDTH * HEIGHT];
} framebuffer;

void draw_pixel(framebuffer* fb, int x, int y, u32 color);
void draw_line(framebuffer* fb, vec2 v0, vec2 v1, u32 color);
void draw_triangle();
void draw_triangle_filled();

#endif
