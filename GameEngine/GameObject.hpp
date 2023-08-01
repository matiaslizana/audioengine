#pragma once

#include <iostream>
#include "Transform.h"
#include "Component.h"
#include "GameScript.h"
#include "IRenderable.h"

class GameScript;

class GameObject
{
private:
	std::vector<Component*> components;
	std::vector<GameScript*> scripts;
	std::vector<GameObject*> children;
	GameObject* parent;
	Transform localTransform;
	std::string name;

	void SetTransform();

public:
	Transform transform;

	GameObject(std::string& name, GameObject* parent = nullptr);
	virtual ~GameObject();
	
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();

	//TODO: Check how to keep the entire object in the list but handling moving them if the list grows
	template<class T>
	T* AddComponent()
	{
		//Keep the whole  
		T* c = new T();
		if (IRenderable* r = dynamic_cast<IRenderable*>(c))
			renderables.push_back(c);
		AddComponent(c);
		return c;
	}

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

	template <class T>
	T* GetGameScript()
	{
		for (size_t i = 0; i < scripts.size(); i++)
		{
			if (T* c = static_cast<T*>(scripts[i]))
				return c;
		}
		return nullptr;
	}

	void Update();
	void AddComponent(Component* c);
	void AddGameScript(GameScript* gs);
	void AddChildren(GameObject* go);
};