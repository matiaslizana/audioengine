#pragma once
#include "GameObject.hpp"

class GameObject;

class GameScript
{
protected:
	GameObject* gameObject;

public:
	GameScript(GameObject* go);
};

