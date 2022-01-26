#include "game.h"

// Game Constructor
game::game()
{
	//SDL stuff
	m_Window = nullptr;
	m_Renderer = nullptr;

	m_World = new World();

	//start_up
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	//create the window
	m_Window = SDL_CreateWindow(
		"The Machokip", // title
		250,               // initial x position
		50,                // initial y position
		1280,               // width in pixels
		1000,               // height in pixels
		0                  // window behavior flags
		);

	if (!m_Window) 
	{
		printf("WINDOW initialisation failed %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}

	m_Renderer = SDL_CreateRenderer(
		m_Window,          // link the renderer to our newly created win
		-1,                // index rendering driver
		0                  // renderer behavior flags
		);

	if (!m_Renderer) 
	{
		printf("RENDERER initialisation failed %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}
	// Creates the scene and generates references to all the objects in the scene

	m_S_Manager = new SceneManager();


	//JSON Data Structure exmple
	//{
	//"name" : "Stone Wall",
	//"fileloc" : "StoneWall.bmp",
	//"tag" : "Wall",
	//"sizeX" : "128",
	//"sizeY" : "128",
	//}  

	// Floor is 512 x 512
	SpawnBitmap("../Assets/Sprites/StoneFloor.bmp", SpriteTypes::Floor);

	// Wall is 128 x 128
	SpawnBitmap("../Assets/Sprites/StoneWall.bmp", SpriteTypes::Wall);

	// Enemy is 151 x 115
	SpawnBitmap("../Assets/Sprites/Slime.bmp", SpriteTypes::Enemy);

	// Player is 160 x 230
	string FileLoc = "../Assets/Sprites/Machokip.bmp";
	Positions = m_S_Manager->GetPlayerStart();
	m_Player = new Player(m_Renderer, FileLoc, Positions);
}

game::~game()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}

// Calls the update components of the game objects once every 60th of a second
void game::GameUpdate()
{
	//loads new scene
	if (m_S_Manager->NewScene)
	{
		floors.clear();
		SpawnBitmap("../Assets/Sprites/StoneFloor.bmp", SpriteTypes::Floor);
		walls.clear();
		SpawnBitmap("../Assets/Sprites/StoneWall.bmp", SpriteTypes::Wall);
		enemies.clear();
		SpawnBitmap("../Assets/Sprites/Slime.bmp", SpriteTypes::Enemy);
		m_Player->SetPos(m_S_Manager->GetPlayerStart());
		m_S_Manager->NewScene = false;
	}

	m_World->Update();

	for (bitmap* floor : floors)
	{
		floor->Draw();
	}

	for (bitmap* wall : walls)
	{
		wall->Draw();
	}

	for (EnemyAI* enemy : enemies)
	{
		enemy->EnemyUpdate();
	}

	m_Player->PlayerUpdate();
}

void game::PreRender()
{
	// Do this once
	SDL_RenderClear(m_Renderer);
}

void game::PostRender()
{
	SDL_RenderPresent(m_Renderer);

	SDL_Delay(16);
}

// Gets the list of bitmaps from the Scene Manager by type of sprite
void game::SpawnBitmap(std::string FileLoc, SpriteTypes Type)
{
	/*
	FloorPos = m_S_Manager->GetObjStart("Floor");
	WallPos = m_S_Manager->GetObjStart("Wall");
	EnemyPos = m_S_Manager->GetObjStart("Enemy");
	for (int i = 0; i < FloorPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < FloorPos[i].size(); j++)
			{
				TempPositions.push_back(FloorPos[i][j]);
			}
			floors.push_back(new bitmap(m_Renderer, FileLoc, TempPositions[0], TempPositions[1]));
		}
	for (int i = 0; i < WallPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < WallPos[i].size(); j++)
			{
				TempPositions.push_back(WallPos[i][j]);
			}
			walls.push_back(new bitmap(m_Renderer, FileLoc, TempPositions[0], TempPositions[1]));
		}
	for (int i = 0; i < EnemyPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < EnemyPos[i].size(); j++)
			{
				TempPositions.push_back(EnemyPos[i][j]);
			}
			enemies.push_back(new EnemyAI(m_Renderer, FileLoc, TempPositions));
		}
	*/
	
	switch (Type)
	{
	case SpriteTypes::Floor:
		FloorPos = m_S_Manager->GetObjStart("Floor");
		for (int i = 0; i < FloorPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < FloorPos[i].size(); j++)
			{
				TempPositions.push_back(FloorPos[i][j]);
			}
			floors.push_back(new bitmap(m_Renderer, FileLoc, TempPositions[0], TempPositions[1]));
		}
		break;

	case SpriteTypes::Wall:
		WallPos = m_S_Manager->GetObjStart("Wall");
		for (int i = 0; i < WallPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < WallPos[i].size(); j++)
			{
				TempPositions.push_back(WallPos[i][j]);
			}
			walls.push_back(new bitmap(m_Renderer, FileLoc, TempPositions[0], TempPositions[1]));
		}
		break;

	case SpriteTypes::Enemy:
		EnemyPos = m_S_Manager->GetObjStart("Enemy");
		for (int i = 0; i < EnemyPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < EnemyPos[i].size(); j++)
			{
				TempPositions.push_back(EnemyPos[i][j]);
			}
			enemies.push_back(new EnemyAI(m_Renderer, FileLoc, TempPositions));
		}
		break;

	/*case SpriteTypes::Item:
		ItemPos = m_S_Manager->GetObjStart("Item");
		for (int i = 0; i < ItemPos.size(); i++)
		{
			std::vector<int> TempPositions;
			for (int j = 0; j < ItemPos[i].size(); j++)
			{
				TempPositions.push_back(ItemPos[i][j]);
			}
			new bitmap(m_Renderer, FileLoc, TempPositions[0], TempPositions[1]);
		}
		break;*/
	}
}

void game::SetDisplayColour(int r, int g, int b, int a)
{
	if (m_Renderer)
	{
		int result = SDL_SetRenderDrawColor(
			m_Renderer,      // our target renderer
			r,               // r
			g,               // b
			b,				 // g
			a				 // alpha
			);
	}
}

SDL_Window* game::GetSdlWindow()
{
	return m_Window;
}

SDL_Renderer* game::GetRenderer()
{
	return m_Renderer;
}

// returns reference of player to main for input
Player* game::GetPlayer()
{
	return m_Player;
}

// returns reference of scene manager to main for input
SceneManager* game::GetManager()
{
	return m_S_Manager;
}
