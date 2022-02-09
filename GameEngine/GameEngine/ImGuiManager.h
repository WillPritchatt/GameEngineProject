#pragma once
#include <SDL.h>
//IMGUI
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
#include "game.h"
#include "SceneManager.h"
class ImGuiManager
{
public:
	ImGuiManager(game* Game, SceneManager* SManager);
	~ImGuiManager();
	void UpdateImGuiWindows();

private:
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	game* m_game;
	SceneManager* m_sManager;
};

