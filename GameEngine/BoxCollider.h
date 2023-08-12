#pragma once
#include <memory>

#include "Bounds.h"
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "GameObject.h"

class BoxCollider : public Component
{
public:
	BoxCollider(std::shared_ptr<GameObject> gObj) : Component(gObj), boundingBox() {}
	BoxCollider(Bounds b, std::shared_ptr<GameObject> gObj) : Component(gObj), boundingBox(b) {}
	BoxCollider(int x, int y, int xExtend, int yExtend, std::shared_ptr<GameObject> gObj) : boundingBox(Vector{ x,y }, Vector{ xExtend, yExtend }), Component(gObj) {}

	Bounds GetBounds();
	void SetPosition(sf::Vector2f position);
	void SetSize(sf::Vector2f size);
	bool CollidesWith(BoxCollider& col);
	void UpdatePosition();
	static void DrawBoxCollider(BoxCollider& boxCollider, sf::RenderWindow& renderWindow);
	bool Collision = false;

private:
	Bounds boundingBox;
};

