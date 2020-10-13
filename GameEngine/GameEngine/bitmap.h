#pragma once

#include <string>
#include <SDL.h>
#include <SDL_render.h>

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
	bitmap(SDL_Renderer* renderer, string fileName, int xpos, int ypos, bool useTransparency = false);
	~bitmap();

	void Draw();

	void SetPos(int X, int Y);
};


