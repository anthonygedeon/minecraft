#include "draw.h"
#include <stdlib.h>
#include <math.h>

#define MAX(a, b)(a>b?a:b)
#define MIN(a, b)(a<b?a:b)

void draw_pixel(framebuffer* fb, int x, int y, u32 color) {
	fb->color_buffer[(WIDTH * y) + x] = color;
}

/// Draws a line between (x1, y1) and (x2, y2) using the Digital Differential Analyzer (DDA) algorithm.
/// This method interpolates points along a straight path by calculating small step sizes.
///
/// The function calculates the difference between the starting and ending coordinates, 
/// determines the number of steps based on the larger absolute difference (dx or dy), 
/// and iterates through the required steps, plotting pixels along the computed path.
///
/// Conceptually, the algorithm works as follows:
///
/// Suppose we want to draw a line from (2,2) to (10,6):
///
/// (x1, y1) = (2,2)       (x2, y2) = (10,6)
///
///      1 2 3 4 5 6 7 8 9
///    1 · · · · · · · · ·
///    2 ●───────────● · ·
///    3 · ● · · · · · · ·
///    4 · · ● · · · · · ·
///    5 · · · ● · · · · ·
///    6 · · · · ●───────●
///
/// The algorithm steps through floating-point x and y values, rounding them to 
/// the nearest integer pixel to approximate the line.
///
/// TODO: Migrate to Brasenham's algorithm if DDA's performance degrades 
void draw_line(framebuffer* fb, vec2 v0, vec2 v1, u32 color) {
	int dx = v1.x - v0.x;
	int dy = v1.y - v0.y;	

	// responsible for determining how many "steps" to take for either axis
	float steps = MAX(abs(dx), abs(dy)); 
	
	/// compute the incremental step size for x and y as floating-point values.
	float x_inc = dx / (float)steps;
	float y_inc = dy / (float)steps;
	
	float x = v0.x;
	float y = v0.y;
	for (int step = 0; step < steps; step++) {
		draw_pixel(fb, round(x), round(y), color);
		x += x_inc;
		y += y_inc;
	}
}
