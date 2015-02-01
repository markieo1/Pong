#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Player.h"
#include "ScoreHandler.h"

/// <summary>
/// A class to display ball.
/// </summary>
class Ball : public PongEngine::GameObject
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Ball"/> class.
	/// </summary>
	Ball() : GameObject() {};

	/// <summary>
	/// Initializes a new instance of the <see cref="Ball"/> class.
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="velocity">The velocity.</param>
	/// <param name="radius">The radius.</param>
	/// <param name="fillColor">Color of the fill.</param>
	/// <param name="moveSpeed">The move speed.</param>
	Ball(sf::Vector2f position, sf::Vector2f velocity, float radius, sf::Color fillColor, float moveSpeed) : GameObject(position, velocity)
	{
		this->moveSpeed = moveSpeed;
		objectColor = fillColor;
		circle = sf::CircleShape(radius);
		circle.setOrigin(radius / 2, radius / 2);
		circle.setPosition(position);
		circle.setFillColor(objectColor);
	};

	/// <summary>
	/// Finalizes an instance of the <see cref="Ball"/> class.
	/// </summary>
	~Ball() {};

	/// <summary>
	/// Do not use this method. It has no function.
	/// </summary>
	/// <param name="deltaTime">The delta time.</param>
	void Update(float deltaTime) {};

	void Ball::Update(float deltaTime, Player* player1, Player* player2);

	/// <summary>
	/// Draws the <see cref="Ball"/>.
	/// </summary>
	/// <param name="drawer">The drawer.</param>
	void Draw(PongEngine::Drawer* drawer);

	/// <summary>
	/// The circle to draw.
	/// </summary>
	sf::CircleShape circle;
protected:
	/// <summary>
	/// The move speed of the <see cref="Ball"/>.
	/// </summary>
	float moveSpeed;

	/// <summary>
	/// The object color of the <see cref="Ball"/>.
	/// </summary>
	sf::Color objectColor;
};

#endif