#include "game.h"
#include "bitmap.h"
#include <string>

#include<SDL.h>

game::game(int X, int Y)
{
	//SDL stuff
	m_Window = nullptr;
	m_Renderer = nullptr;

	m_PlayerX = 50;
	m_PlayerY = 50;

	//start_up
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	m_Window = SDL_CreateWindow(
		"The Machokip", // title
		250,               // initial x position
		50,                // initial y position
		1024,               // width in pixels
		860,               // height in pixels
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

	m_Machokip = new bitmap(m_Renderer, "../Assets/Sprites/Machokip.bmp", m_PlayerX, m_PlayerY, true);
}

game::~game()
{
	if (m_Machokip) 
	{
		delete m_Machokip;
	}

	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}

void game::GameUpdate(int posX, int posY)
{
	// Do this once
	SDL_RenderClear(m_Renderer);

	m_Machokip->SetPos(posX, posY);

	m_Machokip->Draw();

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
