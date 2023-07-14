#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Alien Game");

    Player player {};
    player.SetTexture("resources/assets.png", sf::IntRect(49, 112, 14, 16));
    player.GetSprite().setPosition(400, 300);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(player.GetSprite());

        // end the current frame
        window.display();
    }

    return 0;
}