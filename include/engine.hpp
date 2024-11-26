#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "SDL_render.h"
#include "SDL_video.h"

class Engine {
	public:
		Engine();

		~Engine() = default;

		int init();

		void run();

		void shutdown();


	private:
		SDL_Window   *m_window;
		SDL_Renderer *m_renderer;
};

#endif
