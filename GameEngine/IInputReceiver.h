#pragma once
#include <SFML/Window/Keyboard.hpp>

class IInputReceiver
{
public:
	virtual void OnEventFired(const sf::Keyboard::Key& code) = 0;
};

