#include <string>
#include "GameEngine.h"
#include "SpriteRenderer.h"
#include <memory>
#include "Player.hpp"
#include "GameObject.h"
#include "Weapon.h"

int main()
{
    //TODO: Move this into scripted data (Lua?)
	//TODO: Move game object creation to a pool

	//Player
	std::shared_ptr<GameObject> playerGameObject = std::make_shared<GameObject>("Player");
    GameEngine::Instance().AddGameObject(playerGameObject);

    playerGameObject->SetPosition(sf::Vector2f(400, 300));

	std::shared_ptr<SpriteRenderer> playerSpriteRenderer = GameObject::AddComponent<SpriteRenderer>(playerGameObject);
    playerSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    playerSpriteRenderer->GetSprite()->setScale(-1.f, 1.f);
    playerSpriteRenderer->GetSprite()->setOrigin(8, 8);


    //Weapon
	std::shared_ptr<GameObject> weaponGameObject = std::make_shared<GameObject>("Weapon");
    GameEngine::Instance().AddGameObject(weaponGameObject, playerGameObject);

    weaponGameObject->SetPosition(sf::Vector2f(0, 0));

	std::shared_ptr<SpriteRenderer> weaponSpriteRenderer = GameObject::AddComponent<SpriteRenderer>(weaponGameObject);
    weaponSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
	std::shared_ptr<Weapon> weaponComponent = GameObject::AddComponent<Weapon>(weaponGameObject);

    std::shared_ptr<Player> playerComponent = GameObject::AddComponent<Player>(playerGameObject);
    GameEngine::Instance().SubscribeInput(playerComponent);

	GameEngine::Instance().Init();

    return 0;
}