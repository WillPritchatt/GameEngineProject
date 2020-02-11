#include "bitmap.h"
#include <string>

#include <SDL.h>
#include <SDL_render.h>



bitmap::bitmap(SDL_Renderer* renderer, string fileName, int xpos, int ypos, bool useTransparency)
{
	m_pRenderer = renderer;

	m_pBitmapSurface = SDL_LoadBMP(fileName.c_str());
	if (!m_pBitmapSurface)
	{
		printf("SURFACE for bitmap '%s' not loaded! \n", fileName.c_str());
		printf("%s\n", SDL_GetError());
	}
	else 
	{
		if (useTransparency)
		{
			Uint32 colourKey = SDL_MapRGB(m_pBitmapSurface->format, 255, 0, 255);
			SDL_SetColorKey(m_pBitmapSurface, SDL_TRUE, colourKey);
		}

		m_pBitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pBitmapSurface);
		if (!m_pBitmapTexture) 
		{
			printf("TEXTURE for bitmap '%s' not loaded! \n", fileName.c_str());
			printf("%s\n", SDL_GetError());
		}
	}

	m_x = xpos;
	m_y = ypos;
}

void bitmap::Draw()
{
	if (m_pBitmapTexture)
	{
		SDL_Rect destRect = { m_x, m_y, m_pBitmapSurface->w, m_pBitmapSurface->h };
		SDL_RenderCopy(m_pRenderer, m_pBitmapTexture, NULL, &destRect);
	}
}

bitmap::~bitmap()
{
	if (m_pBitmapTexture) 
	{
		SDL_DestroyTexture(m_pBitmapTexture);
	}

	if (m_pBitmapSurface)
	{
		SDL_FreeSurface(m_pBitmapSurface);
	}
}

