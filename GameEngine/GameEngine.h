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
	std::vector<GameObject*> gameObjects{};
	std::vector<IRenderable*> renderables{};

public:
	GameEngine();
	void Init();
	void AddGameObject(GameObject* gameObject);
	void SubscribeInput(Player* player);
};
