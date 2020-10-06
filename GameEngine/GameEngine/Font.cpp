#include "font.h"

font::font()
{

}

font::font(std::string filePath, int size)
{
	const char* charFilePath = filePath.c_str();
	TTF_OpenFont(charFilePath, size);
}

font::~font()
{
}

void font::UpdateText(std::string msg, int x, int y, TTF_Font* font, SDL_Color colour, SDL_Renderer* renderer)
{
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	int textW = 0;
	int textH = 0;

	surface = TTF_RenderText_Solid(font, msg.c_str(), colour);
	if (!surface) 
	{
		printf("SURFACE for font not loaded \n");
		printf("%s\n", SDL_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (!texture)
		{
			printf("Texture for font not loaded \n");
			printf("%s\n", SDL_GetError());
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
			SDL_Rect textRect = { x, y, textW, textH };

			SDL_RenderCopy(renderer, texture, NULL, &textRect); 
		}
	}

	if (texture)
		SDL_DestroyTexture(texture);
	if (surface)
		SDL_FreeSurface(surface);
}
