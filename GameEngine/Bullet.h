#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Bullet : public GameObject
{
private:
	float velocity;
public:
	Bullet(float velocity);
	void Render(sf::RenderWindow& renderWindow) override;
};