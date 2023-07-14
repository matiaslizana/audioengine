#include "GameObject.hpp"

GameObject::GameObject() : texture{}, sprite{}
{

}

void GameObject::SetTexture(std::string texturePath, sf::IntRect rect)
{
	if (!texture.loadFromFile(texturePath, rect))
	{
		std::cout << "Error loading texture " << texturePath << std::endl;
	}
	sprite.setTexture(texture);
}

sf::Sprite& GameObject::GetSprite()
{
	return sprite;
}