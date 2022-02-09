#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>// replace
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	std::vector<int> GetPlayerStart();
	std::vector<std::vector<int>> GetObjStart(std::string Object);
	std::string HoldSceneName;
	void LoadScene(std::string SceneName);
	void SavePlayer(std::string SceneName, std::vector<int> PlayerPos);

	

	bool NewScene;

private:
	std::string FilePath;
	std::string TempFilePath;
	std::string Line;

	std::vector<std::string> ReadResult;
	std::vector<std::string> TempFiles;

	std::map<int, std::string> Tiles;

	json SceneJson;

	void DrawScene(std::vector<std::string> SceneData);
	std::string WallLoc = "../Assets/Sprites/StoneWall.bmp";
	std::string FloorLoc = "../Assets/Sprites/StoneFloor.bmp";
	std::string XLoc;
	std::string YLoc;
	std::string str;
	void CreateTempFile(std::string SceneName);
	void DeleteTempFiles();

};