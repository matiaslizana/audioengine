#include "GameEngine.h"

GameEngine::GameEngine() : input{}, window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Alien Game"), gameObjects{}, renderables{}
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

void GameEngine::DestroyGameObject(std::shared_ptr<GameObject> gameObject)
{
	gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
	renderables.erase(std::remove(renderables.begin(), renderables.end(), gameObject->GetComponent<IRenderable>()), renderables.end());
	std::cout << gameObject->GetName() << " destroyed" << std::endl;
}

void GameEngine::AddRenderable(std::shared_ptr<IRenderable> renderable)
{
	renderables.push_back(renderable);
}
