#pragma once
//SDL & STD
#include <SDL.h>
#include <SDL_TTF.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <filesystem>
//Own Code
#include "bitmap.h"
#include "SceneManager.h"
#include "Player.h"
#include "World.h"
#include "EnemyAI.h"
//Json Parser
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

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

	std::vector<std::string> ListOfFilePaths;

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

	void PreRender();
	void PostRender();

	SDL_Window* GetSdlWindow();
	SDL_Renderer* GetRenderer();

	json AssetsList;

	Player* GetPlayer();
	SceneManager* GetManager();
};


