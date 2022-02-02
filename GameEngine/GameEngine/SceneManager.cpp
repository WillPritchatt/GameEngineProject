#include "SceneManager.h"

// SceneManager Constructor
SceneManager::SceneManager()
{
	NewScene = false;
	LoadScene("Scene1");
}

//Scene JSON Data Example
//{
//"Scene 1" : { //Scene Name
//	"Floor" : { //Object Tag
//		"FileLoc" : "StoneFloor.bmp", //Object File Location
//		"Positions : [
//		"0,0",
//		"0, 128",
//		"128, 0",
//		"128, 128"]}
//  "Wall
//
//
//
//
//



// Opens the txt file containing the scene data
void SceneManager::LoadScene(std::string SceneName)
{
	HoldSceneName = SceneName;
	ReadResult.clear();
	FilePath = "../Scenes/" + SceneName + ".txt";
	TempFilePath = "../Scenes/" + SceneName + "Temp.txt";
	bool makeTemp = true;
	std::ifstream myFile(FilePath);
	std::ifstream tempMyFile(TempFilePath);


	// Checks to see if any temporary scene files have been created
	if (!TempFiles.empty())
	{
		for (int i = 0; i < TempFiles.size(); i++)
		{
			if (TempFiles[i] == TempFilePath)
			{
				makeTemp = false;
			}
		}
	}

	// If there are no temporary scenes, load the scene from the default
	if (makeTemp)
	{
		tempMyFile.close();
		while (std::getline(myFile, Line))
		{
			ReadResult.push_back(Line);
		}
		myFile.close();
	}
	// If there is a temporary scene, load the scene from the temporary scene
	else
	{
		while (std::getline(tempMyFile, Line))
		{
			ReadResult.push_back(Line);
		}
		tempMyFile.close();
		myFile.close();
	}

	// If there were no temporary scenes, create the temporary scene
	if (makeTemp)
		CreateTempFile(SceneName);
}

// When changing scenes, save player position to the temporary scene
void SceneManager::SavePlayer(std::string SceneName, std::vector<int> PlayerPos)
{
	std::string NewString = "PlayerStart[" + std::to_string(PlayerPos[0]) + "," + std::to_string(PlayerPos[1]) + "]";
	std::vector<std::string> Temp;
	for (int i = 0; i < ReadResult.size(); i++)
	{
		if (ReadResult[i].find("PlayerStart") != std::string::npos)
			Temp.push_back(NewString);
		
		else
			Temp.push_back(ReadResult[i]);
	}

	// Overwrite temporary scene with new scene data
	FilePath = "../Scenes/" + SceneName + "Temp.txt";
	std::ofstream myFile(FilePath, std::ofstream::trunc);
	if (myFile.is_open())
	{
		for (int i = 0; i < Temp.size(); i++)
		{
			myFile << Temp[i] + "\n";
		}
	}
	myFile.close();
}

// Create a new temporary scene from the existing default scene
void SceneManager::CreateTempFile(std::string SceneName)
{
	FilePath = "../Scenes/" + SceneName + "Temp.txt";
	TempFiles.push_back(FilePath);
	std::ofstream myFile(FilePath, std::ofstream::trunc);
	if (myFile.is_open())
	{
		for (int i = 0; i < ReadResult.size(); i++)
		{
			myFile << ReadResult[i] + "\n";
		}
	}
	myFile.close();
}



SceneManager::~SceneManager()
{

}

// Gets the player starting position from the Scene File, returns vector of positions
// There should only be one player start
std::vector<int> SceneManager::GetPlayerStart()
{
	std::vector<int> PlayerPos;
	for (int i = 0; i < ReadResult.size(); i++)
	{
		std::size_t found = ReadResult[i].find("PlayerStart");
		std::cout << ReadResult[i];
		if (found != std::string::npos)
		{
			XLoc = "";
			YLoc = "";
			str = ReadResult[i];
			found = str.find("[");
			std::size_t found2 = str.find(",");
			std::size_t found3 = str.find("]");
			for (int j = found + 1; j < found2; j++)
				XLoc = XLoc + str.at(j);
			
			for (int j = found2 + 1; j < found3; j++)
				YLoc = YLoc + str.at(j);

			std::cout << XLoc;
			//converts string to int
			PlayerPos.push_back(std::stoi(XLoc));
			PlayerPos.push_back(std::stoi(YLoc));
		}
	}
	return PlayerPos;
}
// Returns list of all object positions from the Scene File
std::vector<std::vector<int>> SceneManager::GetObjStart(std::string Object)
{
	std::vector<std::vector<int>> ListOfObjPos;
	for (int i = 0; i < ReadResult.size(); i++)
	{
		std::size_t found = ReadResult[i].find(Object);
		if (found != std::string::npos)
		{
			std::vector<int> ObjPos;
			XLoc = "";
			YLoc = "";
			str = ReadResult[i];
			found = str.find("[");
			std::size_t found2 = str.find(",");
			std::size_t found3 = str.find("]");
			for (int j = found + 1; j < found2; j++)
				XLoc = XLoc + str.at(j);

			for (int j = found2 + 1; j < found3; j++)
				YLoc = YLoc + str.at(j);

			//converts string to int
			ObjPos.push_back(std::stoi(XLoc));
			ObjPos.push_back(std::stoi(YLoc));
			ListOfObjPos.push_back(ObjPos);
		}
	}
	return ListOfObjPos;
}
