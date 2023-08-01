#pragma once
#include "GameObject.hpp"

class GameObject;

//TODO: GameScript change to component
class GameScript
{
protected:
	GameObject* gameObject;

public:
	GameScript(GameObject* go);
};

