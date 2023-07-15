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

void GameObject::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(sprite);
}

void GameObject::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

sf::Vector2f GameObject::GetPosition()
{
	return sprite.getPosition();
}

//DISCUSS: What is better? Maybe that's only for convenience functions, but not for basic ones
/*
void Render(GameObject& gameObject, sf::RenderWindow& renderWindow)
{
	renderWindow.draw(gameObject.GetSprite());
}
*/