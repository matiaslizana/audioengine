#include "Weapon.h"

Weapon::Weapon(std::shared_ptr<GameObject> go) : Component(go)
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
}

void Weapon::Shot()
{
	std::cout << "Shot!" << std::endl;
}
