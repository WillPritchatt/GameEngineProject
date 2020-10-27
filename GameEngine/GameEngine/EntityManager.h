#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <string>
class EntityManager
{
protected:
	std::vector<int>EntList;

	enum ComponentFlags
	{
		No_Components = 0,
		Sprite_Mask = 1,
		Move_Mask = 2,
		Position_Mask = 4,
		Collider_Mask = 8,
	};

public:
	EntityManager();
	void AddEntity(std::string Name, bool duplicate); 
	int FindEntity(std::string Name);

	std::map<std::string, int> Entities; // string - Variable Name, int- Position in the EntList 


private:
	int FindNextFree();
	void AddComponents();
	unsigned int NextFreeIndex = 0;
};

