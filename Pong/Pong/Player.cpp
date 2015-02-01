#include "Player.h"

void Player::Update(float deltaTime)
{
	position += velocity * deltaTime;
	rectangle.setPosition(position);
}

void Player::HandleInput()
{
	//Get the width and height of the window
	sf::Vector2u windowSize = PongEngine::Drawer::windowSize;
	if (sf::Keyboard::isKeyPressed(moveKeyUp))
	{
		velocity.y = -moveSpeed;
		if (position.y < 4)
		{
			velocity.y = 0.0f;
		}
	}
	else if (sf::Keyboard::isKeyPressed(moveKeyDown))
	{
		velocity.y = +moveSpeed;
		if ((position.y + rectangle.getSize().y) > (windowSize.y - 4))
		{
			velocity.y = 0.0f;
		}
	}
	else
	{
		velocity.y = 0.0f;
	}
}

void Player::Draw(PongEngine::Drawer* drawer)
{
	drawer->GameWindow->draw(rectangle);
}