#include "Weapon.h"

Weapon::Weapon(std::shared_ptr<GameObject> go) : Component(go)
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
}

void Weapon::Shot() const
{
	std::shared_ptr<GameObject> bulletGameObject = std::make_shared<GameObject>("Bullet");
	GameEngine::Instance().AddGameObject(bulletGameObject);

	sf::Vector2f weaponPosition = gameObject->GetPosition();
	weaponPosition.x += 10.0f;
	weaponPosition.y += 3.0f;
	bulletGameObject->SetPosition(weaponPosition);

	std::shared_ptr<SpriteRenderer> bulletSpriteRenderer = GameEngine::Instance().AddSpriteRenderer(bulletGameObject);
	bulletSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(246, 54, 4, 4));
	bulletSpriteRenderer->GetSprite()->setOrigin(2, 2);

	GameObject::AddComponent<Bullet>(bulletGameObject);

	std::cout << "Shot!" << std::endl;
}
