#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Input.h"
#include "Weapon.h"

int main()
{
    //TODO: Make Render a singleton?
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Game");

    Input input {};

    Player player {};
    player.SetTexture("resources/assets.png", sf::IntRect(64, 112, 16, 16));
    player.GetSprite().setPosition(400, 300);
    
    Weapon weapon {};
    weapon.SetTexture("resources/assets.png", sf::IntRect(152, 102, 13, 8));
    weapon.GetSprite().setPosition(100, 100);

    //Subscribe players to input (action, instance, num of parameters)
    input.Subscribe(std::bind(&Player::OnEventFired, &player, std::placeholders::_1));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        input.PollEvent(window);
        window.clear(sf::Color::Black);
        player.Render(window);
        weapon.Render(window);
        window.display();
    }

    return 0;
}