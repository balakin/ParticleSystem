#include "Scene.hpp"

#include <stdexcept>

bool Scene::changeBlocked;
Scene* Scene::currentScene;
std::map<std::string, std::function<Scene* ()>> Scene::sceneConstructors;

bool Scene::IsRegistered(const std::string& name)
{
	auto it = sceneConstructors.find(name);
	return it != sceneConstructors.end();
}

std::vector<std::string> Scene::GetNamesOfRegistered()
{
	std::vector<std::string> registered(sceneConstructors.size());
	for (auto const& pair : sceneConstructors)
	{
		registered.push_back(pair.first);
	}

	return registered;
}

void Scene::Load(const std::string& name)
{
	if (changeBlocked)
	{
		return;
	}

	CloseCurrent();
	auto it = sceneConstructors.find(name);
	if (it == sceneConstructors.end())
	{
		return;
	}

	currentScene = it->second();
	currentScene->Initialize();
}

Scene& Scene::GetCurrent()
{
	if (currentScene == nullptr)
	{
		throw std::runtime_error("No scene");
	}

	return *currentScene;
}

void Scene::CloseCurrent()
{
	if (changeBlocked || currentScene == nullptr)
	{
		return;
	}

	changeBlocked = true;
	currentScene->OnDestroy();
	changeBlocked = false;
	delete currentScene;
	currentScene = nullptr;
}

bool Scene::CurrentExists()
{
	return currentScene != nullptr;
}

void Scene::Update() { }

void Scene::Render() { }

void Scene::UI() { }

void Scene::OnDestroy() { }

bool Scene::IsDestroyed() const
{
	return isDestroyed;
}
