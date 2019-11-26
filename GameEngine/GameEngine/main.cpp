#include <SDL.h>
#include <string>
#include "game.h"
#include "input.h"
#undef main

int main(int argc, char* argv[])
{
	game* Game = new game();
	input* Input = new input();

	if (Game&&Input)
	{

		Uint8 r = 127, g = 127, b = 127, a = 255;
		while (!Input->KeyIsPressed(KEY_ESCAPE)) 
		{
			Input->Update();

			if (Input->KeyIsPressed(KEY_R)) 
			{
				if (++r > 255) r = 0;
			}

			if (Input->KeyIsPressed(KEY_G)) 
			{
				if (++g > 255) g = 0;
			}

			if (Input->KeyIsPressed(KEY_B)) 
			{
				if (++b > 255) b = 0;
			}
			Game->SetDisplayColour(r, g, b, a);
			Game->GameUpdate();
		}

		delete Game;
		Game = nullptr;

		delete Input;
		Input = nullptr;
	}

	return 0;
}
