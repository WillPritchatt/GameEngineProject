#include "bitmap.h"

// Constructor for the bitmap, transparency is true by default in header.
bitmap::bitmap(SDL_Renderer* renderer, string& fileName, int xpos, int ypos, bool useTransparency)
{
	m_pRenderer = renderer;

	if (TextureManager::GetInstance()->Load(fileName, useTransparency, renderer, &m_pBitmapTexture, &m_pBitmapSurface))
		std::cout << "Error loading bitmap" << std::endl;

	m_x = xpos;
	m_y = ypos;
}
// Draws the bitmap if there is a loaded texture
void bitmap::Draw()
{
	if (m_pBitmapTexture)
	{
		SDL_Rect destRect = { m_x, m_y, m_pBitmapSurface->w, m_pBitmapSurface->h };
		SDL_RenderCopy(m_pRenderer, m_pBitmapTexture, NULL, &destRect);
	}
}

// Sets Bitmap Position
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

// Checks to see if a texture has already been loaded before loading a texture to memory;
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

