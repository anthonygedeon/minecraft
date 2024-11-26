#ifndef FRAME_BUFFER_HPP
#define FRAME_BUFFER_HPP

#include "SDL_pixels.h"
#include "SDL_render.h"
#include <cstdint>
#include <vector>

class FrameBuffer {
public:
	SDL_Texture *m_texture;

    std::vector<uint8_t> m_pixels;

    FrameBuffer(SDL_Renderer *renderer, int width, int height)
        : m_width{ width }
        , m_height{ height }
        , m_pixels(width * height * 4, 0)
		, m_texture{  SDL_CreateTexture(renderer, 
			SDL_PIXELFORMAT_RGBA32, 
			SDL_TEXTUREACCESS_STREAMING, 
			width, 
			height) }
    {
    }

    ~FrameBuffer() = default;

	int get_width();
	int get_height();

	void clear();

	void draw_pixel(int x, int y, SDL_Color color);

	void draw_line(int x0, int y0, int x1, int y1, SDL_Color color);

	void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, SDL_Color color);

	void update(SDL_Renderer* renderer);

private:
    int m_width;
    int m_height;
};

#endif
