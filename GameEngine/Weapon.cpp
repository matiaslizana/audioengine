#include "Weapon.h"

Weapon::Weapon(std::shared_ptr<GameObject> go) : Component(go)
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
}

void Weapon::Shot()
{
	std::shared_ptr<GameObject> bulletGameObject = std::make_shared<GameObject>("Bullet");
	GameEngine::Instance().AddGameObject(bulletGameObject);

	std::shared_ptr<SpriteRenderer> bulletSpriteRenderer = GameObject::AddComponent<SpriteRenderer>(bulletGameObject);
	bulletSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(246, 54, 4, 4));
	bulletSpriteRenderer->GetSprite()->setOrigin(2, 2);

	GameObject::AddComponent<Bullet>(bulletGameObject);

	std::cout << "Shot!" << std::endl;
}
