#pragma once

#include "Component.h"
#include "IInputReceiver.h"
#include "SpriteRenderer.h"
//#include "Weapon.h"

class Player : public Component, public IInputReceiver
{
private:
	float velocity;
	bool lastDirectionLeft;
	std::shared_ptr<SpriteRenderer> spriteRenderer;
	//Weapon* weapon;

public:
	Player(std::shared_ptr<GameObject> go);
	virtual ~Player() = default;

	void OnEventFired(const sf::Keyboard::Key& code) override;
};