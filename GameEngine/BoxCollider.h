#pragma once
#include "Bounds.h"
#include "SFML/Graphics.hpp"

class BoxCollider
{
public:
	BoxCollider(Bounds b) : boundingBox(b) {}
	BoxCollider(int x, int y, int xExtend, int yExtend) : boundingBox(Vector{ x,y }, Vector{ xExtend, yExtend }) {}

	void Draw(sf::RenderWindow& renderWindow);
	bool Collides(const BoxCollider& col);

private:
	Bounds boundingBox;
};

