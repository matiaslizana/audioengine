#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Weapon.h"
#include "Bullet.h"

class Player : public GameScript
{
private:
	float velocity;
	bool lastDirectionLeft;

public:
	Player();
	//TODO: How to bind Keyboard to Player without Keyboard class coupled?
	void OnEventFired(sf::Keyboard::Key code);
};