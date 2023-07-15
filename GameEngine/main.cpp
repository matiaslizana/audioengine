#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Input.h"

int main()
{
    //TODO: Make Render a singleton?
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Game");

    Player player {};
    player.SetTexture("resources/assets.png", sf::IntRect(49, 112, 14, 16));
    player.GetSprite().setPosition(400, 300);

    Input input {};

    // run the program as long as the window is open
    while (window.isOpen())
    {
        input.PollEvent(window);
        window.clear(sf::Color::Black);
        player.Render(window);
        window.display();
    }

    return 0;
}