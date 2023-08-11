#pragma once
#include "GameObject.h"
#include "Component.h"
#include "SpriteRenderer.h"

class Bullet : public Component
{
private:
	float velocity;
	std::shared_ptr<SpriteRenderer> spriteRenderer;

public:
	Bullet(std::shared_ptr<GameObject> go, float velocity);

	void Update() override;
};