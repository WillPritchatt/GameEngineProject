#include "bitmap.h"
#include <string>


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

		m_pBitmapTexture = Load(fileName);
		if (!m_pBitmapTexture) 
		{
			m_pBitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pBitmapSurface);
			if (!m_pBitmapTexture)
			{
				printf("TEXTURE for bitmap '%s' not loaded! \n", fileName.c_str());
				printf("%s\n", SDL_GetError());
			}
			else
			{
				textures.insert(std::pair<std::string, SDL_Texture*>(fileName, m_pBitmapTexture));
			}
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

void bitmap::SetPos(int X, int Y)
{
	m_x = X;
	m_y = Y;
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

SDL_Texture* bitmap::Load(std::string fileName)
{
	SDL_Texture* m_pBitmapTexture = nullptr;

	//if the texture is already loaded, return the pointer to that texture
	auto search = textures.find(fileName);
	if (search != textures.end())
	{
		m_pBitmapTexture = textures[fileName];
	}
	//if the texture is not loaded, create and return a pointer to that texture

	return m_pBitmapTexture;
}

