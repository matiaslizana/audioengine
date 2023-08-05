#include "Player.hpp"

Player::Player(std::shared_ptr<GameObject> go) : Component(go), velocity(0.05f), lastDirectionLeft(false)
{
	spriteRenderer = gameObject->GetComponent<SpriteRenderer>();
	//weapon = gameObject->GetGameScript<Weapon>();
}

void Player::OnEventFired(const sf::Keyboard::Key& code)
{
	sf::Vector2f position = gameObject->GetPosition();

	if (code == sf::Keyboard::Left)
	{
		position.x -= velocity;
		if (!lastDirectionLeft)
		{
			spriteRenderer->GetSprite()->setScale(1.f,1.f);
			lastDirectionLeft = true;
		}
	}
	if (code == sf::Keyboard::Right)
	{
		position.x += velocity;
		if (lastDirectionLeft)
		{

			spriteRenderer->GetSprite()->setScale(-1.f, 1.f);
			lastDirectionLeft = false;
		}
	}

	if (code == sf::Keyboard::Up)
		position.y -= velocity;
	if (code == sf::Keyboard::Down)
		position.y += velocity;
	
	if (code == sf::Keyboard::Space)
	{
		//weapon->Shot();
	}

	gameObject->SetPosition(position);
}
