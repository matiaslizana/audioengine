#include "GameEngine.h"
#include "BoxCollider.h"

GameEngine::GameEngine() : input{}, window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Alien Game"), gameObjects{}, renderables{}
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

		PhysicsSystem.Update();

		// DEBUG DRAWING 
#if _DEBUG
		PhysicsSystem.DebugDraw(window);
#endif
		// END DEBUG DRAWING

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