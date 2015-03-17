#ifndef GUIRECTANGLE_H
#define GUIRECTANGLE_H
#include <SFML\Graphics.hpp>
namespace PongEngine
{
	namespace GUI
	{
		class GuiRectangle
		{
		public:
			GuiRectangle();

			GuiRectangle(sf::Vector2f position, sf::Vector2f size);

			GuiRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color borderColor, float borderSize);

			/// <summary>
			/// Gets the position of the button.
			/// </summary>
			/// <returns>A Vector2 with the position.</returns>
			virtual sf::Vector2f GetPosition();

			/// <summary>
			/// Sets the x position of the button.
			/// </summary>
			/// <param name="x">The x.</param>
			virtual void SetXPosition(float x);

			/// <summary>
			/// Sets the y position of the button.
			/// </summary>
			/// <param name="y">The y.</param>
			virtual void SetYPosition(float y);

			/// <summary>
			/// Sets the position of the button.
			/// </summary>
			/// <param name="x">The x.</param>
			/// <param name="y">The y.</param>
			virtual void SetPosition(float x, float y);

			/// <summary>
			/// Sets the position of the button.
			/// </summary>
			/// <param name="position">The position.</param>
			virtual void SetPosition(sf::Vector2f position);

			/// <summary>
			/// Gets the size of the button.
			/// </summary>
			/// <returns>The size in a Vector2.</returns>
			virtual sf::Vector2f GetSize();

			/// <summary>
			/// Sets the width of the button.
			/// </summary>
			/// <param name="width">The width.</param>
			virtual void SetWidth(float width);

			/// <summary>
			/// Sets the height of the button.
			/// </summary>
			/// <param name="height">The height.</param>
			virtual void SetHeight(float height);

			/// <summary>
			/// Sets the size of the button.
			/// </summary>
			/// <param name="width">The width.</param>
			/// <param name="height">The height.</param>
			virtual void SetSize(float width, float height);

			/// <summary>
			/// Sets the size of the button.
			/// </summary>
			/// <param name="size">The size.</param>
			virtual void SetSize(sf::Vector2f size);

			/// <summary>
			/// Gets the color of the border.
			/// </summary>
			/// <returns>The color of the border.</returns>
			virtual sf::Color GetBorderColor();

			/// <summary>
			/// Sets the color of the border.
			/// </summary>
			/// <param name="color">The color.</param>
			virtual void SetBorderColor(sf::Color color);

			/// <summary>
			/// Gets the color of the background.
			/// </summary>
			/// <returns>The color of the background off the button.</returns>
			virtual sf::Color GetBackgroundColor();

			/// <summary>
			/// Sets the color of the background.
			/// </summary>
			/// <param name="color">The color.</param>
			virtual void SetBackgroundColor(sf::Color color);

			/// <summary>
			/// Gets the size of the border.
			/// </summary>
			/// <returns>The size of the border.</returns>
			virtual float GetBorderSize();

			/// <summary>
			/// Sets the size of the border.
			/// </summary>
			/// <param name="size">The size.</param>
			virtual void SetBorderSize(float size);
		protected:
			sf::RectangleShape rectangle;
		};
	}
}
#endif