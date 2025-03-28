#include <SDL.h>
#include <stdio.h>
#include <string.h>
#include "SDL_error.h"
#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_timer.h"
#include "SDL_video.h"
#include "types.h"
#include "stdbool.h"
#include "window.h"
#include "draw.h"
#define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
// #define STBI_ONLY_PNG

//              A R G B
#define WHITE 0xFFFFFFFF
#define BLACK 0xFF000000


typedef struct {
	SDL_Window*   window;
	SDL_Renderer* renderer;
} window;



void print_error(void) {
	fprintf(stderr, "%s", SDL_GetError());
}

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		print_error();
		return -1;
	}

	window win;
	framebuffer fb;
	win.window = SDL_CreateWindow("Minecraft", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	if (win.window == NULL) {
		print_error();
		return -1;
	}

	win.renderer = SDL_CreateRenderer(win.window, -1, 0);
	if (win.renderer == NULL) {
		print_error();
		return -1;
	}

	SDL_Texture* texture = SDL_CreateTexture(win.renderer, SDL_PIXELFORMAT_ARGB8888, 
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	if (texture == NULL) {
		print_error();
		return -1;
	}

	bool quit = false;
	SDL_Event e;

	while(!quit) {
		while(SDL_PollEvent(&e) != 0) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}
		}


		SDL_UpdateTexture(texture, NULL, fb.color_buffer, WIDTH * sizeof(u32));
		SDL_RenderClear(win.renderer);
		SDL_RenderCopy(win.renderer, texture, NULL, NULL);
		SDL_RenderPresent(win.renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(win.renderer);
	SDL_DestroyWindow(win.window);
	SDL_Quit();
	
	return 0;
}
