#include "GameEngine.h"
#include "BoxCollider.h"

GameEngine::GameEngine() : input{}, window(sf::VideoMode(800, 600), "Alien Game")
{
}

void GameEngine::Init()
{
	while (window.isOpen())
	{
		input.PollEvent(window);
		window.clear(sf::Color::Black);
		for (int i = 0; i < gameObjects.size(); i++)
			gameObjects[i]->Render(window);

		BoxCollider b{ 25, 25, 50, 50 };
		b.Draw(window);

		window.display();
	}
}

void GameEngine::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void GameEngine::SubscribeInput(Player* player)
{
	input.Subscribe(std::bind(&Player::OnEventFired, player, std::placeholders::_1));
}
