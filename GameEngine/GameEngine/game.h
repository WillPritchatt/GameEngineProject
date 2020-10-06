#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <stdio.h>
#include <SDL_TTF.h>
class bitmap;
class font;

class game
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	bitmap* m_Machokip;

	font* m_DrawFont;

	TTF_Font* m_pSmallFont;
	TTF_Font* m_pBigFont;

	int m_PlayerX;
	int m_PlayerY;

public:
	game(int X, int Y);
	~game();

	void GameUpdate(int posX, int posY);

	void SetDisplayColour(int r, int g, int b, int a);
};
#endif

