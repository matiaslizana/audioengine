#pragma once

#include <vector>
#include <memory>
#include "Component.h"
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
	GameObject(const std::string& name);
	virtual ~GameObject() = default;
	
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();

	//TODO: Check how to keep the entire object in the list but handling moving them if the list grows
	template<class T>
	static std::shared_ptr<T> AddComponent(std::shared_ptr<GameObject> gameObject)
	{
		std::shared_ptr<T> c = std::make_shared<T>(gameObject);
		if (const std::shared_ptr<IRenderable> r = std::dynamic_pointer_cast<IRenderable>(c))
			GameEngine::Instance().AddRenderable(r);
		gameObject->AddComponent(c);
		return c;
	}

	template <class T>
	std::shared_ptr<T> GetComponent(bool searchOnchildren = false)
	{
		for (const auto& component : components)
		{
			if (std::shared_ptr<T> c = std::dynamic_pointer_cast<T>(component))
				return c;
		}

		if (!searchOnchildren)
			return nullptr;

		for (const auto& child : children)
		{
			if (std::shared_ptr<T> c = std::dynamic_pointer_cast<T>(child->GetComponent<T>()))
				return c;
		}

		return nullptr;
	}

	void Update();
	void AddComponent(std::shared_ptr<Component> c);
	void AddChildren(std::shared_ptr<GameObject> go);
	void SetParent(std::shared_ptr<GameObject> parent);
};