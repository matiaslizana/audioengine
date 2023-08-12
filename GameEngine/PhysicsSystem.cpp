#include "PhysicsSystem.h"
#include "BoxCollider.h"

void PhysicsSystem::Update()
{
	for (auto& col : boxColliders)
	{
		col->UpdatePosition();
	}

	for (int i = 0; i < boxColliders.size(); ++i)
	{
		std::shared_ptr<BoxCollider> b = boxColliders[i];
		for (int j = i + 1; j < boxColliders.size(); ++j)
		{
			if (b->CollidesWith(*boxColliders[j]))
			{
				b->Collision = true;
			}
		}
	}
}


void PhysicsSystem::AddBoxCollider(std::shared_ptr<BoxCollider> box)
{
	boxColliders.push_back(box);
}

void PhysicsSystem::DebugDraw(sf::RenderWindow& window)
{
	for (auto& col : boxColliders)
	{
		BoxCollider::DrawBoxCollider(*col, window);
	}
}
