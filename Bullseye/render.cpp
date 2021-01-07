#include <render.h>
#include "globals.h"

char buffer[256];
bool bTest = false;

bool bFirstTime = true;

void render::draw_info(IDirect3DDevice9* pDevice) {
	DrawStringOutline("Bullseye", 15, 10, 255, 255, 255, 255, pFontUISmall);
}

void render::draw_crosshair(IDirect3DDevice9* pDevice) {
	//left
	DrawOverlayRectangle(954, 539, 959, 541, 250, 255, 0, 0);
	//top
	DrawOverlayRectangle(959, 534, 961, 539, 250, 255, 0, 0);
	//right
	DrawOverlayRectangle(961, 539, 966, 541, 250, 255, 0, 0);
	//bottom
	DrawOverlayRectangle(959, 541, 961, 546, 250, 255, 0, 0);
}

void render::draw_menu(IDirect3DDevice9* pDevice) {
	//ImGui Custom Colors
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.62f, 0.93f, 0.06f, 1.00f);

	//ImGui Frame
	ImGui_ImplDX9_NewFrame();

	DWORD dwFlag = ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

	bool _visible;
	_visible = true;
	static int tab = 0;

	if (bFirstTime)
		ImGui::SetNextWindowSize(ImVec2(400, 300));

	ImGui::Begin("Bullseye", &_visible, dwFlag);

	ImGui::Checkbox("Crosshair", &Globals::show_crosshair);

	ImGui::End();

	ImGui::Render();

	bFirstTime = false;
}