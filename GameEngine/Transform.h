#pragma once
#include <SFML/Graphics.hpp>

class Transform
{
public:
	sf::Vector2f position;
	
	Transform();
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();
};