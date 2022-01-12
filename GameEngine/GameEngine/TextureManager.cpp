#include "TextureManager.h"

TextureManager* TextureManager::Instance = nullptr;

int TextureManager::Load(std::string& fileName, bool useTransparency, SDL_Renderer* renderer, SDL_Texture** texture, SDL_Surface** surface)
{
	//SDL_Texture* m_pBitmapTexture = nullptr;

	//if the texture is already loaded, return the pointer to that texture
	auto search = TextureManager::GetInstance()->textures.find(fileName);
	if (search != TextureManager::GetInstance()->textures.end())
	{
		*texture = TextureManager::GetInstance()->textures[fileName];
	}
	//if the texture is not loaded, create and return a pointer to that texture
	//else
	{
		//SDL_Surface* pTempSurface = SDL_LoadBMP(fileName.c_str());
		SDL_Surface* surface2 = SDL_LoadBMP(fileName.c_str());
		*surface = surface2;
		//*surface = SDL_LoadBMP(fileName.c_str());
		if (!*surface)
		{
			printf("SURFACE for bitmap '%s' not loaded! \n", fileName.c_str());
			printf("%s\n", SDL_GetError());
			return 1;
		}
		else
		{
			if (useTransparency)
			{
				Uint32 colourKey = SDL_MapRGB(surface2->format, 255, 0, 255);
				SDL_SetColorKey(*surface, SDL_TRUE, colourKey);
			}

			*texture = SDL_CreateTextureFromSurface(renderer, *surface);
			if (!*texture)
			{
				printf("TEXTURE for bitmap '%s' not loaded! \n", fileName.c_str());
				printf("%s\n", SDL_GetError());
				return 1;
			}
			TextureManager::GetInstance()->textures.insert(std::pair< std::string, SDL_Texture*>(fileName, *texture));
			TextureManager::GetInstance()->surfaces.insert(std::pair<std::string, SDL_Surface*>(fileName, surface2));
		}
	}

	return 0; //no errors
}