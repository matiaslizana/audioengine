#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "BoxCollider.h"

class GameObject
{
private:
	sf::Texture texture;
	BoxCollider collider;

protected:
	sf::Sprite sprite;

public:
	GameObject();
	void SetTexture(std::string texturePath, sf::IntRect rect);
	sf::Sprite& GetSprite();
	virtual void Render(sf::RenderWindow& renderWindow);
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();
};
