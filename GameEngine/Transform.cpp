#include "Transform.h"

void Transform::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f Transform::GetPosition()
{
	return position;
}
