#include "GameEngine.h"

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

		for (int i = 0; i < renderables.size(); i++)
			renderables[i]->Render(window);

		window.display();
	}
}

void GameEngine::SubscribeInput(const std::shared_ptr<IInputReceiver>& receiver)
{
	input.Subscribe(std::bind(&IInputReceiver::OnEventFired, receiver, std::placeholders::_1));
}

void GameEngine::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void GameEngine::AddRenderable(const std::shared_ptr<IRenderable>& renderable)
{
	renderables.push_back(renderable);
}