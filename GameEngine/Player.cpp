#include "Player.hpp"
#include "GameEngine.h"
#include "Singleton.h"

extern Singleton<GameEngine> gameEngine;

Player::Player() : velocity(0.05f), lastDirectionLeft(false)
{

}

void Player::OnEventFired(sf::Keyboard::Key code)
{
	//sf::Vector2f position = sprite.getPosition();

	//if (code == sf::Keyboard::Left)
	//{
	//	position.x -= velocity;
	//	if (!lastDirectionLeft)
	//	{
	//		sprite.setScale(1.f,1.f);
	//		lastDirectionLeft = true;
	//	}
	//}
	//if (code == sf::Keyboard::Right)
	//{
	//	position.x += velocity;
	//	if (lastDirectionLeft)
	//	{
	//		sprite.setScale(-1.f, 1.f);
	//		lastDirectionLeft = false;
	//	}
	//}

	//if (code == sf::Keyboard::Up)
	//	position.y -= velocity;
	//if (code == sf::Keyboard::Down)
	//	position.y += velocity;
	
	if (code == sf::Keyboard::Space)
	{
		//QUESTION: Objects need to be created inside the game engine (to keep the reference there)
		//Do we need to create a templated version for GameObject derived classes?
		//Or maybe classes should not derive from GameObject, and have like a component based behavior as unity? How can we do that?
		/*
		Bullet bullet{ velocity };
		gameEngine.Instance().AddGameObject(&bullet);
		*/
	}

	//sprite.setPosition(position);
}
