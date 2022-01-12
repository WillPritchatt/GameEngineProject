#include "World.h"


// Constructs the physics world
World::World()
{
	b2Vec2 Gravity(0.0, 0.0);
	NewWorld = new b2World(Gravity);
	timeStep = 1.0f / 60.0f;
	VelocityInteractions = 6;
	PositionInteractions = 2;
}

World::~World()
{

}

// Updates the physics world
void World::Update()
{
	NewWorld->Step(timeStep, VelocityInteractions, PositionInteractions);
}
