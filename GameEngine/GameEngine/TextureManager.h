#pragma once
#include <map>
#include <string>
#include <SDL.h>


//struct SDL_Texture;
//struct of Texture Surface
class TextureManager
{

public:

	static TextureManager* Instance;
	static TextureManager* GetInstance()
	{
		if (TextureManager::Instance == nullptr)
			TextureManager::Instance = new TextureManager();
		return TextureManager::Instance;
	}


	int Load(std::string& fileName, bool useTransparency, SDL_Renderer* renderer, SDL_Texture** texture, SDL_Surface** sruface);
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, SDL_Surface*> surfaces;

private:

};

