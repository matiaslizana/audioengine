#pragma once
#include "GameObject.h"
#include "Component.h"
#include "SpriteRenderer.h"
#include "GameConfig.h"

class Bullet : public Component
{
private:
	float velocity;
	std::shared_ptr<SpriteRenderer> spriteRenderer;

public:
	Bullet(std::shared_ptr<GameObject> go);

	void Update() override;
};