#include <SDL.h>
#include <string>
#include "game.h"
#include "input.h"
#include "bitmap.h"
#undef main

int main(int argc, char* argv[])
{
	game* Game = new game();
	input* Input = new input();

	Uint8 r = 127, g = 127, b = 127, a = 255;

	while (Game&&Input)
	{
		Input->Update();
		if (Input->KeyIsPressed(SDL_SCANCODE_R)) 
		{
			r++;
			if (++r > 255) r = 0;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_G))
		{
			g++;
			if (++g > 255) g = 0;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_B))
		{
			b++;
			if (++b > 255) b = 0;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_W))
		{
			
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_A))
		{

		}

		if (Input->KeyIsPressed(SDL_SCANCODE_S))
		{

		}

		if (Input->KeyIsPressed(SDL_SCANCODE_D))
		{
			
		}


		Game->SetDisplayColour(r, g, b, a);
		Game->GameUpdate();
	}

	delete Game;
	Game = nullptr;

	delete Input;
	Input = nullptr;

	return 0;
}
