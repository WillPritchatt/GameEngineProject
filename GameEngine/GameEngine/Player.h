#pragma once
#include "bitmap.h"
#include "input.h"
#include <vector>
#include <box2d/box2d.h>

class Player
{
public:
	float startX;
	float startY;
	float xPos;
	float yPos;

	input* Input;
	bitmap* Bitmap;

	Player(SDL_Renderer* renderer, string& fileName, std::vector<int> Positions);
	~Player();

	void PlayerUpdate();
	vector<int> GetPos();
	void SetPos(std::vector<int> Positions);
	b2BodyDef GetPlayerBodyDef();
	

private:

	b2BodyDef PlayerBodyDef;
	void CreateBodyDef();
};

