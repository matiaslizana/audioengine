#pragma once

#include "Input.h"
#include <memory>
#include "IInputReceiver.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "GameConfig.h"
#include <iostream>
#include "SpriteRenderer.h"
#include "Pool.h"

class GameObject;

class GameEngine
{
private:
	Input input;
	sf::RenderWindow window;
	std::vector<std::shared_ptr<GameObject>> gameObjects;
	std::vector<std::shared_ptr<SpriteRenderer>> renderables;

public:

	Pool<SpriteRenderer> spriteRendererPool;

	GameEngine();
	static GameEngine& Instance()
	{
		static GameEngine instance;
		return instance;
	}

	void Init();
	void SubscribeInput(std::shared_ptr<IInputReceiver> receiver);
	void AddGameObject(std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> parent = nullptr);
	void DestroyGameObject(std::shared_ptr<GameObject> gameObject);
	std::shared_ptr<SpriteRenderer> AddSpriteRenderer(std::shared_ptr<GameObject> gameObject);
};
