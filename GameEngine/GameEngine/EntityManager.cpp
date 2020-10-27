#include "EntityManager.h"

EntityManager::EntityManager()
{
	EntList.push_back(0000);
}

void EntityManager::AddEntity(std::string Name, bool duplicate)
{
	int ID = FindNextFree();
	EntList[ID] = (No_Components);
	Entities[Name] = ID;
	
}

int EntityManager::FindEntity(std::string Name)
{
	return 0;
}

int EntityManager::FindNextFree()
{
	int temp = NextFreeIndex;
	NextFreeIndex++;
	return temp;
}

void EntityManager::AddComponents()
{
	
}
