#include "BoxCollider.h"

Bounds BoxCollider::GetBounds()
{
	return boundingBox;
}

void BoxCollider::SetPosition(sf::Vector2f position)
{
	const Vector v{static_cast<int>(position.x), static_cast<int>(position.y) };
	boundingBox.SetPosition(v);
}

void BoxCollider::SetSize(sf::Vector2f size)
{
	const Vector v{static_cast<int>(size.x * 0.5f), static_cast<int>(size.y * 0.5f) };
	boundingBox.SetExtends(v);
}

void BoxCollider::DrawBoxCollider(BoxCollider& boxCollider, sf::RenderWindow& renderWindow)
{
	Bounds bounds = boxCollider.GetBounds();
	const Vector center = bounds.GetCenter();
	const Vector extends = bounds.GetExtends();
	sf::Vector2f position {	(float)(bounds.GetMinPosition().x),
							(float)(bounds.GetMinPosition().y)
						  };

	sf::Vector2f size {(float)extends.x * 0.5f, (float) extends.y * 0.5f};
	sf::RectangleShape rect;

	rect.setPosition(position);
	rect.setSize(size);

	rect.setOutlineColor(sf::Color(0, 255, 0));
	rect.setOutlineThickness(1);
	rect.setFillColor(sf::Color(0, 0, 0, 0));
	renderWindow.draw(rect);
}
