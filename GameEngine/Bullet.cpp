#include "Bullet.h"

Bullet::Bullet(std::shared_ptr<GameObject> go, float velocity) : Component(go), velocity(velocity)
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
}

void Bullet::Update()
{
	sf::Vector2f position = gameObject->GetPosition();
	position.x -= velocity;
	gameObject->SetPosition(position);
}