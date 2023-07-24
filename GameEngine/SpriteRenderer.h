#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Component.h"
#include "IRenderable.h"
#include <iostream>

class SpriteRenderer : public Component, public IRenderable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	void SetTexture(std::string texturePath, sf::IntRect rect);
	void Render(sf::RenderWindow& renderWindow) override;
	void SetTransform(Transform* t) override;
	sf::Sprite* GetSprite();
};