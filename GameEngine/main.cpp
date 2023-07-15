#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Input.h"
#include "Weapon.h"
#include "GameEngine.h"

int main()
{
    //TODO: Make GameEngine a singleton
    GameEngine gameEngine{};

    //TODO: Move this into scripted data (Lua?)
    Player player {};
    player.SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    player.GetSprite().setPosition(400, 300);
    player.GetSprite().setScale(-1.f, 1.f);
    player.GetSprite().setOrigin(8, 8);
    gameEngine.AddGameObject(&player);
    gameEngine.SubscribeInput(&player);

    Weapon weapon {};
    weapon.SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    gameEngine.AddGameObject(&weapon);
    player.AssignWeapon(&weapon);
    
    //Bullet: 246, 54, 4, 4  
    gameEngine.Init();

    return 0;
}