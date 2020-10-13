#pragma once

#include <map>
#include <memory>
#include <string>

template<typename T>
class ResourceManager
{

private:
	int currentID;
	std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;

	int Add(const std::string& filePath)
	{
		auto it = resources.find(filePath);
		if (it != resources.end())
		{
			return it->second.first;
		}

		std::shared_ptr<T> resource = std::make_shared<T>();
		if (!resource.loadFromFile(filePath))
		{
			return -1;
		}

		resources.insert(std::make_pair(filePath, std::make_pair(currentID, resource)));
		return currentID++;
	}

	void Remove(int id)
	{
		for (auto it = resources.begin(); it != resources.end(); ++it)
		{
			if (it->second.first == id)
			{
				resource.erase(it->first);
			}
		}
	}

	std::shared_ptr<T> Get(int id)
	{
		for (auto it = resources.begin(); it != resources.end(); ++it)
		{
			if (it->second.first == id)
			{
				return it->second.second;
			}
		}

		return nullptr
	}

	bool Has(int id)
	{
		return(Get(id)) != nullptr);
	}
};



