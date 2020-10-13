#include "TextureManager.h"

SDL_Texture* TextureManager::Load(std::string fileName, bool useTransparency, SDL_Renderer* renderer)
{
	SDL_Texture* m_pBitmapTexture = nullptr;

	//if the texture is already loaded, return the pointer to that texture
	auto search = textures.find(fileName);
	if (search != textures.end())
	{
		m_pBitmapTexture = textures[fileName];
	}
	//if the texture is not loaded, create and return a pointer to that texture
	else
	{
		SDL_Surface* pTempSurface = SDL_LoadBMP(fileName.c_str());
		if (!pTempSurface)
		{
			printf("SURFACE for bitmap '%s' not loaded! \n", fileName.c_str());
			printf("%s\n", SDL_GetError());
		}
		else
		{
			if (useTransparency)
			{
				Uint32 colourKey = SDL_MapRGB(pTempSurface->format, 255, 0, 255);
				SDL_SetColorKey(pTempSurface, SDL_TRUE, colourKey);
			}

			m_pBitmapTexture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
			if (!m_pBitmapTexture)
			{
				printf("TEXTURE for bitmap '%s' not loaded! \n", fileName.c_str());
				printf("%s\n", SDL_GetError());
			}
		}
	}

	return m_pBitmapTexture;
}
