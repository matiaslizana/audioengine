#include <string>
#include "GameEngine.h"
#include "SpriteRenderer.h"
#include <memory>
#include "Player.hpp"
#include "GameObject.hpp"

int main()
{
    //TODO: Move this into scripted data (Lua?)
    std::string playerName = "Player";

    //TODO: Move game object creation to a pool
    GameObject playerGameObject {playerName};
    playerGameObject.SetPosition(sf::Vector2f(400, 300));

    const std::shared_ptr<SpriteRenderer> playerSpriteRenderer = playerGameObject.AddComponent<SpriteRenderer>();
    playerSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    playerSpriteRenderer->GetSprite()->setScale(-1.f, 1.f);
    playerSpriteRenderer->GetSprite()->setOrigin(8, 8);
    
    const std::shared_ptr<Player> playerGameScript = playerGameObject.AddComponent<Player>();
   
    GameEngine::Instance().SubscribeInput(playerGameScript);
    GameEngine::Instance().AddGameObject(&playerGameObject);

    //std::string weaponName = "Weapon";
    //GameObject weaponGameObject{weaponName, &playerGameObject};
    //weaponGameObject.SetPosition(sf::Vector2f(0, 0));

    //SpriteRenderer* weaponSpriteRenderer = weaponGameObject.AddComponent<SpriteRenderer>();
    //weaponSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    //
    //Weapon* weaponGameScript = new Weapon(&weaponGameObject);

    //GameEngine::Instance().AddGameObject(&weaponGameObject);
    
    //Bullet: 246, 54, 4, 4  
    GameEngine::Instance().Init();

    return 0;
}