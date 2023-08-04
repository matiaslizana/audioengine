#pragma once
#include "GameObject.h"
#include "SpriteRenderer.h"

class Weapon : public Component
{
private:
	std::shared_ptr<SpriteRenderer> spriteRenderer;

public:
	Weapon(std::shared_ptr<GameObject> go);
	virtual ~Weapon() = default;

	void Shot();
};