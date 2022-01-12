#include "Player.h"

// Constructor is passed the requirements to draw the bitmap
Player::Player(SDL_Renderer* renderer, string& fileName, std::vector<int> Positions)
{
	SetPos(Positions);
	CreateBodyDef();
	Bitmap = new bitmap(renderer, fileName, Positions[0], Positions[1]);
}

Player::~Player()
{
	
}

// Update function so object can handle its own rendering and movement
void Player::PlayerUpdate()
{
	Bitmap->SetPos(xPos, yPos);
	Bitmap->Draw();
}

// Returns the x and y position of the object
vector<int> Player::GetPos()
{
	std::vector<int> Positions;
	Positions.push_back(xPos);
	Positions.push_back(yPos);
	return Positions;
}

// Sets the position of the object when constructed
void Player::SetPos(std::vector<int> Positions)
{
	xPos = Positions[0];
	yPos = Positions[1];
}

// Box2d function to get the Player Body definiton
b2BodyDef Player::GetPlayerBodyDef()
{
	return PlayerBodyDef;
}

// Box2d function to define the Player Body
void Player::CreateBodyDef()
{
	PlayerBodyDef.type = b2_dynamicBody;
	PlayerBodyDef.position.Set(128, 128);
}



