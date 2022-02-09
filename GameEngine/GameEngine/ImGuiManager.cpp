#include "ImGuiManager.h"

ImGuiManager::ImGuiManager(game* Game, SceneManager* SManager)
{
	m_game = Game;
	m_sManager = SManager;
	m_window = m_game->GetSdlWindow();
	m_renderer = m_game->GetRenderer();;
	//imGUI setup
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	SDL_DisplayMode DisplayMode;
	SDL_GetCurrentDisplayMode(0, &DisplayMode);
	ImGuiSDL::Initialize(m_renderer, DisplayMode.w, DisplayMode.h);
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForOpenGL(m_window, SDL_GL_GetCurrentContext());
}

ImGuiManager::~ImGuiManager()
{
}

void ImGuiManager::UpdateImGuiWindows()
{
	//Update each ImGui window each frame;
	ImGui::NewFrame();
	ImGui_ImplSDL2_NewFrame(m_window);
	bool show = false;

	ImGui::Begin("test");
	ImGui::End();

	ImGui::ShowDemoWindow(&show);	

	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
}
