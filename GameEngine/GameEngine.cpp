#include "GameEngine.h"
#include "BoxCollider.h"
constexpr int WINDOW_HEIGHT = 600;
constexpr int WINDOW_WIDTH = 800;

GameEngine::GameEngine() : input{}, window(sf::VideoMode(800, 600), "Alien Game"), gameObjects{}, renderables{}
{
}

void GameEngine::Init()
{
	while (window.isOpen())
	{
		input.PollEvent(window);
		window.clear(sf::Color::Black);

		for (int i = 0; i < gameObjects.size(); i++)
			gameObjects[i]->Update();

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

		for (int i = 0; i < renderables.size(); i++)
			renderables[i]->Render(window);

		window.display();
	}
}

void GameEngine::SubscribeInput(std::shared_ptr<IInputReceiver> receiver)
{
	input.Subscribe(std::bind(&IInputReceiver::OnEventFired, receiver, std::placeholders::_1));
}

void GameEngine::AddGameObject(std::shared_ptr<GameObject> gameObject, std::shared_ptr<GameObject> parent)
{
	gameObjects.push_back(gameObject);
	gameObject->SetParent(parent);
	if (parent != nullptr)
		parent->AddChildren(gameObject);
}

void GameEngine::AddRenderable(std::shared_ptr<IRenderable> renderable)
{
	renderables.push_back(renderable);
}