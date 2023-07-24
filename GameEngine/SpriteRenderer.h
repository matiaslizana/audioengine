#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Component.h"
#include <iostream>

class SpriteRenderer : public Component
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	void SetTexture(std::string texturePath, sf::IntRect rect);
	virtual void Render(sf::RenderWindow& renderWindow);
};