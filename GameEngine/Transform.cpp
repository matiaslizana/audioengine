#include "Transform.h"

Transform::Transform() : position {}
{
}

void Transform::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f Transform::GetPosition()
{
	return position;
}
