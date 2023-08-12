#pragma once

#include "Input.h"
#include <memory>
#include "PhysicsSystem.h"
#include "IRenderable.h"
#include "IInputReceiver.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "GameObject.h"

constexpr int WINDOW_HEIGHT = 600;
constexpr int WINDOW_WIDTH = 800;

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
	PhysicsSystem PhysicsSystem {};

	void Init();
	void SubscribeInput(std::shared_ptr<IInputReceiver> receiver);
	void AddGameObject(std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> parent = nullptr);
	void AddRenderable(std::shared_ptr<IRenderable> renderable);
};
