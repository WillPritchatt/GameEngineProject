#pragma once

#include <map>
#include <string>
#include <SDL_render.h>
#include <IOstream>
#include "TextureManager.h"

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
using namespace std;
class bitmap
{
private:
	SDL_Surface* m_pBitmapSurface;
	SDL_Texture* m_pBitmapTexture;
	SDL_Renderer* m_pRenderer;

	int m_x, m_y;

public:
	bitmap(SDL_Renderer* renderer, string& fileName, int xpos, int ypos, bool useTransparency = true);
	~bitmap();

	SDL_Texture* Load(std::string fileName);
	std::map<std::string, SDL_Texture*> textures;

	void Draw();

	void SetPos(int X, int Y);
};


