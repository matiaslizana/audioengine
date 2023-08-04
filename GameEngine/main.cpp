#include <string>
#include "GameEngine.h"
#include "SpriteRenderer.h"
#include <memory>
#include "Player.hpp"
#include "GameObject.h"

int main()
{
    //TODO: Move this into scripted data (Lua?)
	//TODO: Move game object creation to a pool

	//Player
	std::shared_ptr<GameObject> playerGameObject = std::make_shared<GameObject>("Player");
    playerGameObject->SetPosition(sf::Vector2f(400, 300));

	std::shared_ptr<SpriteRenderer> playerSpriteRenderer = playerGameObject->AddComponent<SpriteRenderer>();
    playerSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    playerSpriteRenderer->GetSprite()->setScale(-1.f, 1.f);
    playerSpriteRenderer->GetSprite()->setOrigin(8, 8);
    
    std::shared_ptr<Player> playerGameScript = playerGameObject->AddComponent<Player>();
   
    GameEngine::Instance().SubscribeInput(playerGameScript);
    GameEngine::Instance().AddGameObject(playerGameObject);

    //Weapon
	std::shared_ptr<GameObject> weaponGameObject = std::make_shared<GameObject>("Weapon", playerGameObject);
    weaponGameObject->SetPosition(sf::Vector2f(0, 0));

    //const std::shared_ptr<SpriteRenderer> weaponSpriteRenderer = weaponGameObject->AddComponent<SpriteRenderer>();
    //weaponSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));

    //const std::shared_ptr<Weapon> weaponGameScript = weaponGameObject->AddComponent<Weapon>();

    //GameEngine::Instance().AddGameObject(&weaponGameObject);
    
    //Bullet: 246, 54, 4, 4  
    GameEngine::Instance().Init();

    return 0;
}