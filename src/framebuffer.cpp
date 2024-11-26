#include "SDL_log.h"
#include "SDL_pixels.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "framebuffer.hpp"

// TODO: Add Double buffer to store pixels
void FrameBuffer::clear() {
	std::fill(m_pixels.begin(), m_pixels.end(), 0);
}

int FrameBuffer::get_width() {
	return m_width;
}

int FrameBuffer::get_height() {
	return m_height;
}

void FrameBuffer::draw_pixel(int x, int y, SDL_Color color) {
	int index = (x + y * m_width) * 4;
	m_pixels[index] = color.r;
	m_pixels[index + 1] = color.g;
	m_pixels[index + 2] = color.b;
	m_pixels[index + 3] = color.a;
}

// TODO: Learn how this works
void FrameBuffer::draw_line(int x0, int y0, int x1, int y1, SDL_Color color) {
	int dx{ std::abs(x1 - x0) };
	int dy{ -std::abs(y1 - y0) };

	int sx{ x0 < x1 ? 1 : -1 };
	int sy{ y0 < y1 ? 1 : -1 };

	int error{ dy + dx };
	while(true) {
		draw_pixel(x0, y0, color);
		if (x0 == x1 && y0 == y1) break;
        int e2{ 2 * error };
        if (e2 >= dy) {
            error = error + dy;
            x0 = x0 + sx;
		}
        if (e2 <= dx) {
            error = error + dx;
            y0 = y0 + sy;
		}
	}
}

void FrameBuffer::draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, SDL_Color color) {
	draw_line(x0, y0, x1, y1, color);
	draw_line(x2, y2, x1, y1, color);
	draw_line(x0, y0, x2, y2, color);
}

void FrameBuffer::update(SDL_Renderer* renderer) {
    int pitch;
    void* lockedPixels;

    if (SDL_LockTexture(m_texture, NULL, &lockedPixels, &pitch) != 0) {
        SDL_Log("Unable to lock texture: %s", SDL_GetError());
        return;
    }

    uint8_t* destPixels = static_cast<uint8_t*>(lockedPixels);
    for (int y = 0; y < m_height; ++y) {
		std::memcpy(destPixels + y * pitch, 
               m_pixels.data() + y * m_width * 4, 
               m_width * 4);
    }

    SDL_UnlockTexture(m_texture);
}

