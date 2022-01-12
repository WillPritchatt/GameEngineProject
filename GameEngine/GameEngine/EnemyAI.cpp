#include "EnemyAI.h"

// Constructor is passed the requirements to draw the bitmap.
EnemyAI::EnemyAI(SDL_Renderer* renderer, string& fileName, std::vector<int> Positions)
{
	SetPos(Positions);
	Bitmap = new bitmap(renderer, fileName, Positions[0], Positions[1]);
	Counter = 0;
	Direction = 0;
}

EnemyAI::~EnemyAI()
{

}
// Returns the x and y position of the object
std::vector<int> EnemyAI::GetPos()
{
	std::vector<int> PosVector;
	PosVector.push_back(xPos);
	PosVector.push_back(yPos);
	return std::vector<int>();
}

// Update function so object can handle its own rendering and movement
void EnemyAI::EnemyUpdate()
{
	Counter += 1;
	if (Counter == 180)
	{
		Direction += 1;
		if (Direction == 4)
			Direction = 0;
		Counter = 0;
	}
	Movement();
	Bitmap->SetPos(xPos, yPos);
	Bitmap->Draw();
}

// Sets the object positions on initialisation
void EnemyAI::SetPos(std::vector<int> Positions)
{
	xPos = Positions[0];
	yPos = Positions[1];
}

// Basic movement for the AI
void EnemyAI::Movement()
{
	if (Direction == 0)
		xPos--;
	else if (Direction == 1)
		yPos--;

	else if (Direction == 2)
		xPos++;
	else
		yPos++;
}
