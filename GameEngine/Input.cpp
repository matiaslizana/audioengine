#include "Input.h"

void Input::PollEvent(sf::RenderWindow& renderWindow)
{
    sf::Event event;
    while (renderWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            renderWindow.close();
        if (event.type == sf::Event::KeyPressed)
        {

        }
    }
}
