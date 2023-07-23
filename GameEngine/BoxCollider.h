#pragma once
#include "Bounds.h"
#include "SFML/Graphics.hpp"

class BoxCollider
{
public:
	BoxCollider() : boundingBox() {}
	BoxCollider(Bounds b) : boundingBox(b) {}
	BoxCollider(int x, int y, int xExtend, int yExtend) : boundingBox(Vector{ x,y }, Vector{ xExtend, yExtend }) {}
	Bounds GetBounds();
	void SetPosition(sf::Vector2f position);
	void SetSize(sf::Vector2f size);
	bool Collides(const BoxCollider& col);
	static void DrawBoxCollider(BoxCollider& boxCollider, sf::RenderWindow& renderWindow);

private:
	Bounds boundingBox;
};


