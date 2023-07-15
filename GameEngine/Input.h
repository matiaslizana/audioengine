#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Input
{
public:
	void Subscribe(const std::function<void(sf::Keyboard::Key)>& handler);
	void PollEvent(sf::RenderWindow& renderWindow);
private:
	std::vector<std::function<void(sf::Keyboard::Key)>> eventHandlers;
	
	void FireEvent(sf::Keyboard::Key code);
};
