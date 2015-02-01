#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

/// <summary>
/// A class to create a Player.
/// </summary>
class Player : public PongEngine::GameObject
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	Player() : GameObject()
	{
		rectangle = sf::RectangleShape(sf::Vector2f(100.f, 10.f));
		moveKeyUp = sf::Keyboard::W;
		moveKeyDown = sf::Keyboard::S;
		moveSpeed = 20.f;
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="position">The position.</param>
	/// <param name="velocity">The velocity.</param>
	/// <param name="scale">The scale.</param>
	/// <param name="fillColor">Color of the <see cref="Player"/>.</param>
	/// <param name="moveSpeed">The move speed.</param>
	/// <param name="upKey">Up key.</param>
	/// <param name="downKey">Down key.</param>
	Player(sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f scale, sf::Color fillColor, float moveSpeed, sf::Keyboard::Key upKey = sf::Keyboard::W, sf::Keyboard::Key downKey = sf::Keyboard::S) : GameObject(position, velocity)
	{
		rectangle = sf::RectangleShape(scale);
		rectangle.setFillColor(fillColor);
		rectangle.setPosition(this->position);
		this->moveSpeed = moveSpeed;
		moveKeyUp = upKey;
		moveKeyDown = downKey;
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="Player"/> class.
	/// </summary>
	~Player() {};

	/// <summary>
	/// Updates the <see cref="Player"/>.
	/// </summary>
	/// <param name="deltaTime">The delta time.</param>
	void Update(float deltaTime);

	/// <summary>
	/// Handles the input.
	/// </summary>
	void HandleInput();

	/// <summary>
	/// Draws the <see cref="Player"/>.
	/// </summary>
	/// <param name="drawer">The drawer.</param>
	void Draw(PongEngine::Drawer* drawer);

	/// <summary>
	/// The rectangle of the <see cref="Player"/>.
	/// </summary>
	sf::RectangleShape rectangle;
protected:
	/// <summary>
	/// The move speed of the <see cref="Player"/>.
	/// </summary>
	float moveSpeed;

	/// <summary>
	/// The key for moving up.
	/// </summary>
	sf::Keyboard::Key moveKeyUp;

	/// <summary>
	/// The key for moving down.
	/// </summary>
	sf::Keyboard::Key moveKeyDown;
};

#endif