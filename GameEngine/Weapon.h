#pragma once
#include "GameObject.hpp"
#include "SpriteRenderer.h"

class Weapon : public GameScript
{
private:
	SpriteRenderer* spriteRenderer;

public:
	Weapon(GameObject* go);

	void Shot();
};
