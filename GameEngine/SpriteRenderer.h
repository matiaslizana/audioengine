#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Transform.h"
#include "GameObject.h"
#include <memory>
#include <string>

class GameObject;
class Component;

class SpriteRenderer : public Component
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SpriteRenderer(std::shared_ptr<GameObject> gameObject);

	void SetTexture(std::string texturePath, sf::IntRect rect);
	void SetTransform(Transform& t) override;
	sf::Sprite* GetSprite();

	void Render(sf::RenderWindow& renderWindow) const;
};