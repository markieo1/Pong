#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\Graphics.hpp>
#include "Drawer.h"
namespace PongEngine
{
	/// <summary>
	/// A class that represent a GameObject
	/// </summary>
	class GameObject
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="GameObject"/> class.
		/// </summary>
		GameObject()
		{
			position = sf::Vector2f(100.f, 100.f);
			velocity = sf::Vector2f(1.f, 1.f);
		}

		/// <summary>
		/// Initializes a new instance of the <see cref="GameObject"/> class.
		/// </summary>
		/// <param name="position">The position.</param>
		/// <param name="velocity">The velocity.</param>
		GameObject(sf::Vector2f position, sf::Vector2f velocity)
		{
			this->position = position;
			this->velocity = velocity;
		}

		/// <summary>
		/// Finalizes an instance of the <see cref="GameObject"/> class.
		/// </summary>
		~GameObject() {}

		/// <summary>
		/// Draws the <see cref="GameObject"/>.
		/// </summary>
		/// <param name="drawer">The drawer.</param>
		virtual void Draw(Drawer* drawer) = 0;

		/// <summary>
		/// Updates the <see cref="GameObject"/>.
		/// </summary>
		/// <param name="deltaTime">The delta time.</param>
		virtual void Update(float deltaTime) = 0;

		/// <summary>
		/// The position of the <see cref="GameObject"/>.
		/// </summary>
		sf::Vector2f position;

		/// <summary>
		/// The velocity of the <see cref="GameObject"/>.
		/// </summary>
		sf::Vector2f velocity;
	};
}

#endif