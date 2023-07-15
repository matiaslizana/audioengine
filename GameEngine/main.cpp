#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Input.h"
#include "Weapon.h"

int main()
{
    //TODO: Make Render a singleton?
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Game");

    //TODO: Move this into a GameEngine class?
    std::vector<GameObject*> gameObjects {};

    Input input {};

    Player player {};
    player.SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    player.GetSprite().setPosition(400, 300);
    player.GetSprite().setScale(-1.f, 1.f);
    player.GetSprite().setOrigin(8, 8);
    gameObjects.push_back(&player);

    Weapon weapon {};
    weapon.SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    gameObjects.push_back(&weapon);

    player.AssignWeapon(&weapon);

    //Subscribe players to input (action, instance, num of parameters)
    input.Subscribe(std::bind(&Player::OnEventFired, &player, std::placeholders::_1));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        input.PollEvent(window);
        window.clear(sf::Color::Black);
        for (int i = 0; i < gameObjects.size(); i++)
            gameObjects[i]->Render(window);
        window.display();
    }

    return 0;
}