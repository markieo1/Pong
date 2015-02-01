#include "Ball.h"

/// <summary>
/// Updates the specified delta time.
/// </summary>
/// <param name="deltaTime">The delta time.</param>
/// <param name="player1">The player1.</param>
/// <param name="player2">The player2.</param>
void Ball::Update(float deltaTime, Player* player1, Player* player2)
{
	sf::Vector2u windowSize = PongEngine::Drawer::windowSize;

	if (position.x < (player1->position.x + player1->rectangle.getSize().x) && position.x > player1->position.x && position.y < (player1->position.y + player1->rectangle.getSize().y) && position.y > player1->position.y)
	{
		//Hit PLAYER 1
		velocity.x = +moveSpeed;
	}

	if ((position.x + circle.getRadius()) > player2->position.x && (position.x + circle.getRadius()) < player2->position.x + player2->rectangle.getSize().x && position.y < player2->position.y + player2->rectangle.getSize().y && position.y > player2->position.y)
	{
		//HIT PLAYER 2
		velocity.x = -moveSpeed;
	}

	if (position.x - (circle.getRadius() / 2) < 0)
	{
		//hit left wall
		ScoreHandler::player2Score++;
		velocity.x = +moveSpeed; // force it to be positive
	}

	if (position.x + (circle.getRadius()) > windowSize.x)
	{
		//hit right wall
		ScoreHandler::player1Score++;
		velocity.x = -moveSpeed; // force it to be negative
	}

	if (position.y - (circle.getRadius() / 2) < 0)
	{
		//hit top wall
		velocity.y = +moveSpeed;
	}

	if (position.y + circle.getRadius() > windowSize.y - 5)
	{
		//hit bottom wall
		velocity.y = -moveSpeed;
	}

	position += velocity * deltaTime;
	circle.setPosition(position);
}

void Ball::Draw(PongEngine::Drawer* drawer)
{
	drawer->GameWindow->draw(circle);
}