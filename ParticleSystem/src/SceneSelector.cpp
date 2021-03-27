#include "SceneSelector.hpp"

#include <imgui.h>

bool SceneSelector::VectorGetter(void* data, int index, const char** outText)
{
	auto& vector = *static_cast<std::vector<std::string>*>(data);
	if (index < 0 || index > vector.size())
	{
		return false;
	}

	*outText = vector[index].c_str();
	return true;
}

void SceneSelector::Render()
{
	if (!isOpened)
	{
		return;
	}

	ImGui::SetNextWindowSize(ImVec2(250, 90), ImGuiCond_Always);
	ImGui::Begin("Scene selector", &isOpened, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	ImGui::Combo("Scenes", &selectedScene, VectorGetter, &scenes, scenes.size());
	ImGui::InvisibleButton("##margin", ImVec2(1, 5));
	if (ImGui::Button("Select", ImVec2(235, 20)))
	{
		Scene::Load(scenes[selectedScene]);
	}
	ImGui::End();
}
