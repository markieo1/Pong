#ifndef DRAWER_H
#define DRAWER_H

#include <SFML/Graphics.hpp>

#include <string>

/// <summary>
/// The Game Engine for Pong.
/// </summary>
namespace PongEngine
{
	/// <summary>
	/// A class that has a Window and texture loading.
	/// </summary>
	class Drawer
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Drawer"/> class.
		/// </summary>
		Drawer() {};

		/// <summary>
		/// Finalizes an instance of the <see cref="Drawer"/> class.
		/// </summary>
		~Drawer() {};

		/// <summary>
		/// Initializes a window.
		/// </summary>
		/// <param name="title">The title.</param>
		/// <param name="xPos">The x position.</param>
		/// <param name="yPos">The y position.</param>
		/// <param name="width">The width.</param>
		/// <param name="height">The height.</param>
		/// <param name="style">The style of the window.</param>
		void Init(std::string title = "Window", int xPos = 0, int yPos = 0, int width = 640, int height = 480, sf::Uint32 style = sf::Style::Close);

		/// <summary>
		/// Creates the window.
		/// </summary>
		/// <param name="title">The title.</param>
		/// <param name="xPos">The x position.</param>
		/// <param name="yPos">The y position.</param>
		/// <param name="width">The width.</param>
		/// <param name="height">The height.</param>
		/// <param name="style">The style of the window.</param>
		void CreateWindow(std::string title, int xPos, int yPos, int width, int height, sf::Uint32 style);

		/// <summary>
		/// Loads the texture.
		/// </summary>
		/// <param name="fileName">Name of the file.</param>
		/// <returns>A texture loaded from a file.</returns>
		sf::Texture* LoadTexture(std::string fileName);

		/// <summary>
		/// The game window.
		/// </summary>
		sf::RenderWindow* GameWindow;

		/// <summary>
		/// The window size in a Vector2.
		/// </summary>
		static sf::Vector2u windowSize;
	};
}
#endif