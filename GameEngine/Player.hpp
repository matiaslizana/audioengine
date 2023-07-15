#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Player : public GameObject
{
private:
	float velocity;

public:
	Player();
	//TODO: How to bind Keyboard to Player without Keyboard class coupled?
	void OnEventFired(sf::Keyboard::Key code);
};