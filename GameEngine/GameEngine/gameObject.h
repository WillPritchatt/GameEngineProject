#pragma once
#include <iostream>
#include <vector>
#include "componentBase.hpp"

class gameObject
{
public:

	gameObject();
	~gameObject();

	void AddComponent(void);

	std::vector<componentBase> ComponentVector;

private:
};

