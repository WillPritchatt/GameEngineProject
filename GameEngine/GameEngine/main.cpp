#include <SDL.h>
#include <string>
#include "game.h"
#undef main

int main(int argc, char* argv[])
{
	game* Game = new game();

	if (Game)
	{
		Game->SetDisplayColour();
		delete Game;
		Game = nullptr;
	}

	return 0;
}
