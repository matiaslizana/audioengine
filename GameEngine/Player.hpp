#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Weapon.h"

class Player : public GameObject
{
private:
	float velocity;
	Weapon* weapon;
	sf::Vector2f weaponOffset;
	bool lastDirectionLeft;

public:
	Player();
	//TODO: How to bind Keyboard to Player without Keyboard class coupled?
	void OnEventFired(sf::Keyboard::Key code);
	void AssignWeapon(Weapon* weapon);
	void Render(sf::RenderWindow& renderWindow) override;
};