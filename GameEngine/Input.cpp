#include "Input.h"

void Input::FireEvent(sf::Keyboard::Key key)
{
    for (const auto& handler : eventHandlers)
        handler(key);
}

void Input::Subscribe(const std::function<void(sf::Keyboard::Key)>& handler)
{
    eventHandlers.push_back(handler);
}

void Input::PollEvent(sf::RenderWindow& renderWindow)
{
    //Window Events
    sf::Event event;
    while (renderWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            renderWindow.close();
    }

    //Device events
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        FireEvent(sf::Keyboard::Left);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        FireEvent(sf::Keyboard::Right);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        FireEvent(sf::Keyboard::Up);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        FireEvent(sf::Keyboard::Down);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        FireEvent(sf::Keyboard::Space);
}