#pragma once

#include <iostream>
#include "Transform.h"
#include "Component.h"
#include "GameScript.h"

class GameScript;

class GameObject
{
private:
	std::vector<Component*> components;
	std::vector<GameScript*> scripts;
	std::vector<GameObject*> children;
	GameObject* parent;
	Transform localTransform;

public:
	Transform transform;

	GameObject(GameObject* parent = nullptr);

	void SetPosition(sf::Vector2f position);
	void UpdatePosition();
	sf::Vector2f GetPosition();

	template <class T>
	T* GetComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (T* c = dynamic_cast<T*>(components[i]))
				return c;
		}
		return nullptr;
	}

	void Update();
	void AddComponent(Component* c);
	void AddGameScript(GameScript* gs);
	void AddChildren(GameObject* go);
};