#pragma once
#include "GameObject.hpp"
#include "SpriteRenderer.h"

class Weapon : public Component
{
private:
	SpriteRenderer* spriteRenderer;

public:
	Weapon(GameObject* go);
	virtual ~Weapon() = default;

	void Shot();
};