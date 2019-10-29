#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <stdio.h>

class game
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
public:
	game();
	~game();

	void GameUpdate(void);

	void SetDisplayColour(int r, int g, int b, int a);
};

#endif

