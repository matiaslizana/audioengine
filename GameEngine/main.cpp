#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GameEngine.h"
#include "SpriteRenderer.h"
#include "Weapon.h"

int main()
{
    //TODO: Move this into scripted data (Lua?)
    std::string playerName = "Player";
    GameObject playerGameObject {playerName};
    playerGameObject.SetPosition(sf::Vector2f(400, 300));

    SpriteRenderer* playerSpriteRenderer = GameEngine::Instance().AddComponent<SpriteRenderer>(&playerGameObject);
    playerSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    playerSpriteRenderer->GetSprite()->setScale(-1.f, 1.f);
    playerSpriteRenderer->GetSprite()->setOrigin(8, 8);
    
    Player* playerGameScript = new Player(&playerGameObject);
   
    GameEngine::Instance().SubscribeInput(playerGameScript);
    GameEngine::Instance().AddGameObject(&playerGameObject);

    std::string weaponName = "Weapon";
    GameObject weaponGameObject{weaponName, &playerGameObject};
    weaponGameObject.SetPosition(sf::Vector2f(0, 0));

    SpriteRenderer* weaponSpriteRenderer = GameEngine::Instance().AddComponent<SpriteRenderer>(&weaponGameObject);
    weaponSpriteRenderer->SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    
    Weapon* weaponGameScript = new Weapon(&weaponGameObject);

    GameEngine::Instance().AddGameObject(&weaponGameObject);
    
    //Bullet: 246, 54, 4, 4  
    GameEngine::Instance().Init();

    return 0;
}