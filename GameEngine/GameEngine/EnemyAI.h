#pragma once
#include <vector>
#include "bitmap.h"

class EnemyAI
{
public:
	EnemyAI(SDL_Renderer* renderer, string& fileName, std::vector<int> Positions);
	~EnemyAI();
	std::vector<int> GetPos();
	void SetPos(std::vector<int> Positions);

	void EnemyUpdate();

	bitmap* Bitmap;

private:
	int xPos;
	int yPos;

	int Counter; // Determins when AI direction should change
	int Direction; // Sets AI direction
	void Movement();
};

