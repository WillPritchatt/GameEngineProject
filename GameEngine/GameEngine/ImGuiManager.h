#pragma once
#include <SDL.h>
//IMGUI
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
class ImGuiManager
{
public:
	ImGuiManager(SDL_Window* window, SDL_Renderer* renderer);
	~ImGuiManager();
	void UpdateImGuiWindows();

private:
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
};

