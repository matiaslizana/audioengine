#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Input.h"
#include "Weapon.h"
#include "GameEngine.h"
#include "Singleton.h"
#include "SpriteRenderer.h"

int main()
{
    //TODO: Move this into scripted data (Lua?)
    GameObject player {};
    player.transform.SetPosition(sf::Vector2f(400, 300));
    SpriteRenderer* spriteRenderer = GameEngine::Instance().AddComponent<SpriteRenderer>(&player);
    spriteRenderer->SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    spriteRenderer->GetSprite()->setScale(-1.f, 1.f);
    spriteRenderer->GetSprite()->setOrigin(8, 8);
    
    GameEngine::Instance().AddGameObject(&player);
    //gameEngine.Instance().SubscribeInput(&player);

    //Weapon weapon {};
    //weapon.SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    //gameEngine.Instance().AddGameObject(&weapon);
    //player.AssignWeapon(&weapon);
    
    //Bullet: 246, 54, 4, 4  
    GameEngine::Instance().Init();

    return 0;
}