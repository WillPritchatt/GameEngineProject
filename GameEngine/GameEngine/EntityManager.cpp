#include "EntityManager.h"

EntityManager::EntityManager()
{
	EntList.push_back(0000);
}

void EntityManager::AddEntity(std::string Name, bool duplicate)
{
	int ID = FindNextFree();
	EntList.push_back(ID);
	EntList[ID] = (No_Components);

	Entities.insert(std::pair<std::string, int>(Name, ID));
	//Entities[Name] = ID;


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
