#include "SpriteRenderer.h"

void SpriteRenderer::SetTexture(std::string texturePath, sf::IntRect rect)
{
	if (!texture.loadFromFile(texturePath, rect))
	{
		std::cout << "Error loading texture " << texturePath << std::endl;
	}
	sprite.setTexture(texture);
}

void SpriteRenderer::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(sprite);
}