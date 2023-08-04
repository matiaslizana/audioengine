#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(const std::shared_ptr<GameObject>& gameObject) : Component(gameObject), texture{}, sprite{}
{
}

void SpriteRenderer::SetTexture(std::string texturePath, sf::IntRect rect)
{
	if (!texture.loadFromFile(texturePath, rect))
	{
		std::cout << "Error loading texture " << texturePath << std::endl;
	}
	sprite.setTexture(texture);
}

void SpriteRenderer::SetTransform(Transform* t)
{
	sprite.setPosition(t->GetPosition());
}

sf::Sprite* SpriteRenderer::GetSprite()
{
	return &sprite;
}

void SpriteRenderer::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(sprite);
}