#include <SDL.h>
#include <string>
#include "game.h"
#include "input.h"
#include "bitmap.h"
#include "gameObject.h"
#undef main

int main(int argc, char* argv[])
{
	int PlayerStartX = 50;
	int PlayerStartY = 50;

	game* Game = new game(PlayerStartX, PlayerStartY);
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
			PlayerStartY -= 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_A))
		{
			PlayerStartX -= 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_S))
		{
			PlayerStartY += 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_D))
		{
			PlayerStartX += 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_SPACE))
		{
			Game->SpawnBitmap(50, 50);
		}


		Game->SetDisplayColour(r, g, b, a);
		Game->GameUpdate(PlayerStartX, PlayerStartY);
	}

	delete Game;
	Game = nullptr;

	delete Input;
	Input = nullptr;

	return 0;
}
