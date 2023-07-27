#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "GameEngine.h"
#include "SpriteRenderer.h"

int main()
{
    //TODO: Move this into scripted data (Lua?)
    GameObject playerGameObject {};
    playerGameObject.SetPosition(sf::Vector2f(400, 300));

    SpriteRenderer* spriteRenderer = GameEngine::Instance().AddComponent<SpriteRenderer>(&playerGameObject);
    spriteRenderer->SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    spriteRenderer->GetSprite()->setScale(-1.f, 1.f);
    spriteRenderer->GetSprite()->setOrigin(8, 8);
    
    Player* playerGameScript = new Player(&playerGameObject);
    playerGameObject.AddGameScript(playerGameScript);
    GameEngine::Instance().SubscribeInput(playerGameScript);

    GameEngine::Instance().AddGameObject(&playerGameObject);

    //Weapon weapon {};
    //weapon.SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    //gameEngine.Instance().AddGameObject(&weapon);
    //player.AssignWeapon(&weapon);
    
    //Bullet: 246, 54, 4, 4  
    GameEngine::Instance().Init();

    return 0;
}