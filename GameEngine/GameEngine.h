#pragma once
#include <vector>
#include "GameObject.hpp"
#include "Input.h"
#include "Player.hpp"

class GameEngine
{
private:
	Input input;
	sf::RenderWindow window;
	std::vector<GameObject*> gameObjects{};

public:
	GameEngine();
	void Init();
	void AddGameObject(GameObject* gameObject);
	void SubscribeInput(Player* player);
};
