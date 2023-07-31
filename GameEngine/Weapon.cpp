#include "Weapon.h"

Weapon::Weapon(GameObject* go) : GameScript(go)
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
}

void Weapon::Shot()
{
	std::cout << "Shot!" << std::endl;
}
