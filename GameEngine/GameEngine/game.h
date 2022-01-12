#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_TTF.h>
#include "bitmap.h"
#include "SceneManager.h"
#include "Player.h"
#include "World.h"
#include "EnemyAI.h"
#include <vector>

// Enum of all the sprite types handled by the Scene Manager
enum class SpriteTypes { Enemy, Wall, Floor, Item, None };

class game
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	Player* m_Player;

	World* m_World;

	SceneManager* m_S_Manager;

	std::vector<EnemyAI*> enemies;
	std::vector<bitmap*> walls;
	std::vector<bitmap*> floors;

	std::vector<int> Positions;
	// List of positions from the scene manager
	std::vector<std::vector<int>> WallPos;
	std::vector<std::vector<int>> FloorPos;
	std::vector<std::vector<int>> EnemyPos;
	std::vector<std::vector<int>> ItemPos;

public:
	game();
	~game();

	void GameUpdate();

	void SpawnBitmap(std::string FileLoc, SpriteTypes Type = SpriteTypes::None);

	void SetDisplayColour(int r, int g, int b, int a);

	Player* GetPlayer();
	SceneManager* GetManager();
};


