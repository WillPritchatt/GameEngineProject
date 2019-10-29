#include "game.h"
#include <string>

#include<SDL.h>

game::game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	//start_up
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	m_Window = SDL_CreateWindow(
		"My First Window", // title
		250,               // initial x position
		50,                // initial y position
		640,               // width in pixels
		480,               // height in pixels
		0                  // window behavior flags
		);

	if (!m_Window) 
	{
		printf("WINDOW initialisation failed %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}

	m_Renderer = SDL_CreateRenderer(
		m_Window,          // link the renderer to our newly created win
		-1,                // index rendering driver
		0                  // renderer behavior flags
		);

	if (!m_Renderer) 
	{
		printf("RENDERER initialisation failed %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}
}

game::~game()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}

void game::GameUpdate(void)
{
	// Do this once
	SDL_RenderClear(m_Renderer);

	SDL_RenderPresent(m_Renderer);

	SDL_Delay(16);
}

void game::SetDisplayColour(int r, int g, int b, int a)
{
	if (m_Renderer)
	{
		int result = SDL_SetRenderDrawColor(
			m_Renderer,      // our target renderer
			r,               // r
			g,               // b
			b,				 // g
			a				 // alpha
			);
	}
}
