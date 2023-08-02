#pragma once

#include "Input.h"
#include <memory>
#include "IRenderable.h"
#include "IInputReceiver.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "GameObject.hpp"

class GameObject;

class GameEngine
{
private:
	Input input;
	sf::RenderWindow window;
	std::vector<GameObject*> gameObjects;
	std::vector<std::shared_ptr<IRenderable>> renderables;

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
	void AddRenderable(std::shared_ptr<IRenderable> renderable);
};
