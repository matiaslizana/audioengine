#pragma once

#include "SFML/Graphics.hpp"

class IRenderable
{
public:
	virtual void Render(sf::RenderWindow& renderWindow) = 0;
};