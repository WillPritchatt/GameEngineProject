#include <SDL.h>
#include <string>
#undef main

void main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	int WinWidth = 800;
	int WinHeight = 600;

	SDL_Window* p_window = SDL_CreateWindow("My win", 100, 100, WinWidth, WinHeight, SDL_WINDOW_SHOWN);

	SDL_Renderer* p_Renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(p_Renderer, 0, 0, 128, 0);

	//SDL_ShowWindow(p_window);

	bool quit = false;

	while (!quit)
	{
		SDL_Event E;
		while (SDL_PollEvent(&E)) 
		{
			if (E.type == SDL_KEYDOWN) 
			{
				if (E.key.keysym.sym == SDLK_d) 
				{
					quit = true;
				}
			}
		}



		SDL_RenderClear(p_Renderer);

		SDL_SetRenderDrawColor(p_Renderer, 0, 0, 128, 0);

		SDL_RenderPresent(p_Renderer);

		SDL_Delay(16);

	}


	SDL_DestroyRenderer(p_Renderer);
	SDL_DestroyWindow(p_window);

	SDL_Quit();

}
