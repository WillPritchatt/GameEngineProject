#pragma once

#include <string>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
using namespace std; //I keep screaming but c++ won't hear me
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
};

class Bitmap
{
};

