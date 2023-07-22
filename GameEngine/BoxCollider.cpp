#include "BoxCollider.h"

void BoxCollider::Draw(sf::RenderWindow& renderWindow)
{
	sf::Vector2f position {	(float)boundingBox.center.x  + boundingBox.minPosition.x, 
							(float) boundingBox.center.y + boundingBox.minPosition.y
						  };

	sf::Vector2f size {(float)boundingBox.extends.x * 0.5f, (float) boundingBox.extends.y * 0.5f};
	sf::RectangleShape rect;

	rect.setPosition(position);
	rect.setSize(size);

	rect.setOutlineColor(sf::Color(0, 255, 0));
	rect.setOutlineThickness(1);
	rect.setFillColor(sf::Color(0, 0, 0, 0));
	renderWindow.draw(rect);
}
