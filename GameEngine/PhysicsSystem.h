#pragma once
#include <memory>
#include <vector>
#include "SFML/Graphics.hpp"

class BoxCollider;

class PhysicsSystem
{
public:
	PhysicsSystem() {};
	~PhysicsSystem()
	{

	}
	void Update();
	void AddBoxCollider(std::shared_ptr<BoxCollider> box);
	void DebugDraw(sf::RenderWindow& window);

private:
	std::vector<std::shared_ptr<BoxCollider>> boxColliders;
};

