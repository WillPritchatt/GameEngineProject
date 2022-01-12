#pragma once
#include <box2d/box2d.h>
#include <iostream>

class World
{
public:
	World();
	~World();

	void Update();

private:
	b2World* NewWorld;
	float timeStep;
	int VelocityInteractions;
	int PositionInteractions;

};

