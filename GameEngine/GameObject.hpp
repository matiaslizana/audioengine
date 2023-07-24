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
	Transform transform;

	GameObject();
	void Process();
	void AddComponent(Component* c);
};
