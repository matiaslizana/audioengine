#include <string>
#include "GameEngine.h"
#include "SpriteRenderer.h"
#include <memory>
#include "Player.hpp"
#include "GameObject.h"
#include "Weapon.h"
#include "BoxCollider.h"

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
    std::shared_ptr<Player> playerGameScript = GameObject::AddComponent<Player>(playerGameObject);
    GameEngine::Instance().SubscribeInput(playerGameScript);
    
    // Player Collider
    std::shared_ptr <BoxCollider > PlayerBoxCollider = GameObject::AddComponent<BoxCollider> (playerGameObject);
    PlayerBoxCollider->SetSize(sf::Vector2f(40, 40));
    GameEngine::Instance().PhysicsSystem.AddBoxCollider(PlayerBoxCollider);

    //Weapon
	std::shared_ptr<GameObject> weaponGameObject = std::make_shared<GameObject>("Weapon");
    GameEngine::Instance().AddGameObject(weaponGameObject, playerGameObject);

    weaponGameObject->SetPosition(sf::Vector2f(0, 0));

	std::shared_ptr<SpriteRenderer> weaponSpriteRenderer = GameObject::AddComponent<SpriteRenderer>(weaponGameObject);
    weaponSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
	std::shared_ptr<Weapon> weaponGameScript = GameObject::AddComponent<Weapon>(weaponGameObject);


    // collider wall Left
	std::shared_ptr<GameObject> WallLeftGameObject = std::make_shared<GameObject>("WallColliderLEFT");
    WallLeftGameObject->SetPosition(sf::Vector2f(50, WINDOW_HEIGHT / 2));
    std::shared_ptr <BoxCollider > WallLeftBoxCollider = GameObject::AddComponent<BoxCollider> (WallLeftGameObject);
    GameEngine::Instance().AddGameObject(WallLeftGameObject);
    WallLeftBoxCollider->SetSize(sf::Vector2f(50, WINDOW_HEIGHT - 40));
    GameEngine::Instance().PhysicsSystem.AddBoxCollider(WallLeftBoxCollider);
    
    // Collider Wall Right
	std::shared_ptr<GameObject> WallRightGameObject = std::make_shared<GameObject>("WallColliderRIGHT");
    WallRightGameObject->SetPosition(sf::Vector2f(WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2));
    std::shared_ptr <BoxCollider > WallRightBoxCollider = GameObject::AddComponent<BoxCollider> (WallRightGameObject);
    GameEngine::Instance().AddGameObject(WallLeftGameObject);
    WallRightBoxCollider->SetSize(sf::Vector2f(50, WINDOW_HEIGHT - 40));
    GameEngine::Instance().PhysicsSystem.AddBoxCollider(WallRightBoxCollider);


    //Bullet: 246, 54, 4, 4  
    GameEngine::Instance().Init();

    return 0;
}