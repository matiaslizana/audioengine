#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "IInputReceiver.h"
#include "GameEngine.h"
#include "SpriteRenderer.h"
#include "Weapon.h"

class Player : public GameScript, public IInputReceiver
{
private:
	float velocity;
	bool lastDirectionLeft;
	SpriteRenderer* spriteRenderer;
	Weapon* weapon;

public:
	Player(GameObject* go);

	void OnEventFired(sf::Keyboard::Key code);
};