#pragma once

#include "Input.h"
#include <memory>
#include "IRenderable.h"
#include "IInputReceiver.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class GameObject;

class GameEngine
{
private:
	Input input;
	sf::RenderWindow window;
	std::vector<std::shared_ptr<GameObject>> gameObjects;
	std::vector<std::shared_ptr<IRenderable>> renderables;

public:
	GameEngine();
	static GameEngine& Instance()
	{
		static GameEngine instance;
		return instance;
	}

	void Init();
	void SubscribeInput(std::shared_ptr<IInputReceiver> receiver);
	void AddGameObject(std::shared_ptr<GameObject> gameObject);
	void AddRenderable(std::shared_ptr<IRenderable> renderable);
};
