#pragma once
#include <SFML/Graphics.hpp>

class Transform
{
private:
	sf::Vector2f position;

public:
	Transform();

	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();
};