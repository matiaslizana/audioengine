#pragma once

#include <vector>
#include <memory>
#include "Component.h"
#include "GameObject.hpp"
#include "Transform.h"
#include <string>
#include "GameEngine.h"

class Component;
class GameEngine;

class GameObject
{
private:
	std::vector<std::shared_ptr<Component>> components;
	std::vector<std::shared_ptr<GameObject>> children;
	std::shared_ptr<GameObject> parent;
	Transform transform;
	Transform localTransform;
	std::string name;

	void SetTransform();

public:
	GameObject(const std::string& name, const std::shared_ptr<GameObject>& parent = nullptr);
	virtual ~GameObject();
	
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();

	//TODO: Check how to keep the entire object in the list but handling moving them if the list grows
	template<class T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> c = std::make_shared<T>(this);
		if (const std::shared_ptr<IRenderable> r = std::dynamic_pointer_cast<IRenderable>(c))
			GameEngine::Instance().AddRenderable(r);
		AddComponent(c);
		return c;
	}

	template <class T>
	std::shared_ptr<T> GetComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (std::shared_ptr<T> c = std::dynamic_pointer_cast<T>(components[i]))
				return c;
		}
		return nullptr;
	}

	void Update();
	void AddComponent(const std::shared_ptr<Component>& c);
	void AddChildren(const std::shared_ptr<GameObject>& go);
};