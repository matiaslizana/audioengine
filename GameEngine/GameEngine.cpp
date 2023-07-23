#include "GameEngine.h"
#include "BoxCollider.h"
constexpr int WINDOW_HEIGHT = 600;
constexpr int WINDOW_WIDTH = 800;

GameEngine::GameEngine() : input{}, window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Alien Game")
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

		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(0, WINDOW_HEIGHT / 2)),
				sf::Vertex(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 2))
			};
			window.draw(line, 2, sf::Lines);
		}
		
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, 0)),
				sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT))
			};
			window.draw(line, 2, sf::Lines);
		}

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
