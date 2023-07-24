#pragma once

#include <iostream>
#include "Transform.h"
#include "Component.h"
#include "GameScript.h"

class GameObject
{
private:
	std::vector<Component*> components;
	std::vector<GameScript*> scripts;

public:
	Transform* transform;
	
	GameObject();

	template<class T>
	T* AddComponent()
	{
		//TODO: type assert
		T* c = new T();
		components.push_back(c);
		return static_cast<T*>(c);
	}

	//void AddGameScript();
	virtual void Render(sf::RenderWindow& renderWindow);
};
