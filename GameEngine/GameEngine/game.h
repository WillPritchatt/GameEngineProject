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

	void SetDisplayColour(void);
};

#endif

