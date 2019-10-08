#include <SDL.h>
#undef main

void main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* p_window = SDL_CreateWindow("My win", 0, 0, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Renderer* p_Renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(p_Renderer, 0, 0, 128, 0);

	SDL_ShowWindow(p_window);

	while (true)
	{
		SDL_RenderClear(p_Renderer);

		SDL_SetRenderDrawColor(p_Renderer, 0, 0, 128, 0);

		//SDL_RenderPresent(p_Renderer);

		SDL_Delay(16);

	}


	SDL_DestroyRenderer(p_Renderer);
	SDL_DestroyWindow(p_window);

	SDL_Quit();

}
