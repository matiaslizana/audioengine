#pragma once
#include <vector>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Input.h"
#include "IRenderable.h"

class GameEngine
{
private:
	Input input;
	sf::RenderWindow window;
	std::vector<GameObject*> gameObjects;
	std::vector<IRenderable*> renderables;

public:
	GameEngine();
	static GameEngine& Instance()
	{
		static GameEngine instance;
		return instance;
	}

	void Init();
	void SubscribeInput(IInputReceiver* receiver);
	void AddGameObject(GameObject* gameObject);

	template<class T>
	T* AddComponent(GameObject* go)
	{
		T* c = new T();
		if (IRenderable* r = dynamic_cast<IRenderable*>(c))
			renderables.push_back(c);
		go->AddComponent(c);
		return c;
	}
};
