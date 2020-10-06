#pragma once
#include <String>
#include "SDL.h"
#include "SDL_ttf.h"

struct SDL_Renderer;
class font
{
private:

	
public:
	font();
	font(std::string filePath, int size);
	~font();
	void UpdateText(std::string msg, int x, int y, TTF_Font* font, SDL_Color colour, SDL_Renderer* renderer);
};

