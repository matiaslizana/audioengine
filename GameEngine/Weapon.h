#pragma once
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Bullet.h"

class Weapon : public Component
{
private:
	std::shared_ptr<SpriteRenderer> spriteRenderer;
	std::shared_ptr<Bullet> bullet;

public:
	Weapon(std::shared_ptr<GameObject> go);
	virtual ~Weapon() = default;

	void Shot();
};