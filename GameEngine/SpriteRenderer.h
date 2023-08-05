#pragma once

#include "Component.h"
#include "IRenderable.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Transform.h"
#include <iostream>

class SpriteRenderer : public Component, public IRenderable
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SpriteRenderer(std::shared_ptr<GameObject> gameObject);

	void SetTexture(std::string texturePath, sf::IntRect rect);
	void SetTransform(Transform& t) override;
	sf::Sprite* GetSprite();

	void Render(sf::RenderWindow& renderWindow) override;
};