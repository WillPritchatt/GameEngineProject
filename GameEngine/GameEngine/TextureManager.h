#pragma once
#include <map>
#include <string>
#include "bitmap.h"

//struct SDL_Texture;

class TextureManager
{
public:

	SDL_Texture* Load(std::string fileName, bool useTransparency, SDL_Renderer* renderer);

private:
	std::map<std::string, SDL_Texture*> textures;
};

