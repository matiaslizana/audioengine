#include "Player.hpp"

Player::Player() : velocity(0.05f)
{

}

void Player::OnEventFired(sf::Keyboard::Key code)
{
	sf::Vector2f position = sprite.getPosition();

	if (code == sf::Keyboard::Left)
		position.x -= velocity;
	if (code == sf::Keyboard::Right)
		position.x += velocity;
	if (code == sf::Keyboard::Up)
		position.y -= velocity;
	if (code == sf::Keyboard::Down)
		position.y += velocity;
	
	//if (code == sf::Keyboard::Space)

	sprite.setPosition(position);
}