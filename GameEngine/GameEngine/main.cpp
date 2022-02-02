//SDL
#include <SDL.h>

//STD
#include <string>
//Own Code
#include "game.h"
#include "input.h"
#include "bitmap.h"
#include "gameObject.h"
#include "EntityManager.h"
#include "ImGuiManager.h"
#undef main

// Main loop of the engine
int main(int argc, char* argv[])
{
	game* Game = new game();
	Player* player = Game->GetPlayer();
	SceneManager* SManager = Game->GetManager();
	input* Input = new input();
	ImGuiManager* IGManager = new ImGuiManager(Game->GetSdlWindow(), Game->GetRenderer());

	EntityManager* Ents = new EntityManager();

	Uint8 r = 127, g = 127, b = 127, a = 255;


	while (Game&&Input)
	{
		int xPlayerPos = player->GetPos()[0];
		int yPlayerPos = player->GetPos()[1];
		Input->Update();

		// Input handling is done in main as input crashed when used anywhere else
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
			 yPlayerPos -= 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_A))
		{
			xPlayerPos -= 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_S))
		{
			yPlayerPos += 1;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_D))
		{
			xPlayerPos += 1;
		}

		// input to change between scene 1 and scene 2
		if (Input->KeyIsPressed(SDL_SCANCODE_1))
		{
			SManager->SavePlayer(SManager->HoldSceneName , player->GetPos());
			SManager->LoadScene("scene1");
			SManager->NewScene = true;
		}

		if (Input->KeyIsPressed(SDL_SCANCODE_2))
		{
			SManager->SavePlayer(SManager->HoldSceneName, player->GetPos());
			SManager->LoadScene("scene2");
			SManager->NewScene = true;
		}


		vector<int> Positions;
		Positions.push_back(xPlayerPos);
		Positions.push_back(yPlayerPos);
		player->SetPos(Positions);
		Game->SetDisplayColour(r, g, b, a);
		Game->PreRender();
		
		
		Game->GameUpdate();

		IGManager->UpdateImGuiWindows();
		
		Game->PostRender();

		//Ents->AddEntity("Player", false);
	}

	delete Game;
	Game = nullptr;

	delete Input;
	Input = nullptr;

	return 0;
}
