#include "Bullet.h"

Bullet::Bullet(float velocity) : velocity(velocity)
{
}

void Bullet::Render(sf::RenderWindow& renderWindow)
{
	GameObject::Render(renderWindow);
	sf::Vector2f position = GetPosition();
	position.x -= velocity;
	SetPosition(position);
}