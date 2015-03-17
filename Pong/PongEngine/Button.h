#ifndef BUTTON_H
#define BUTTON_H

#include "SFML\Graphics.hpp"
#include "Drawer.h"
#include "GUIRectangle.h"
#include <functional>

/// <summary>		
/// The engine for the Pong Game.
/// </summary>
namespace PongEngine
{
	/// <summary>		
	/// GUI Items for <see cref="PongEngine"/> namespace.
	/// </summary>
	namespace GUI
	{
		/// <summary>		
		/// A class to create a button.
		/// </summary>
		class Button : public GuiRectangle
		{
		public:
			std::function<void(Button*)> OnMouseClickEvent;
			std::function<void(Button*)> OnMouseHoverEvent;
			std::function<void(Button*)> OnMouseEnterEvent;
			std::function<void(Button*)> OnMouseLeaveEvent;

			/// <summary>
			/// Initializes a new instance of the <see cref="Button"/> class.
			/// </summary>
			Button();

			/// <summary>
			/// Initializes a new instance of the <see cref="Button"/> class.
			/// </summary>
			/// <param name="buttonText">The button text.</param>
			/// <param name="textColor">Color of the text.</param>
			/// <param name="buttonFont">The button font.</param>
			/// <param name="position">The position.</param>
			/// <param name="size">The size.</param>
			Button(std::string buttonText, sf::Color textColor, sf::Font* buttonFont, sf::Vector2f position, sf::Vector2f size);

			/// <summary>
			/// Initializes a new instance of the <see cref="Button"/> class.
			/// </summary>
			/// <param name="buttonText">The button text.</param>
			/// <param name="textColor">Color of the text.</param>
			/// <param name="buttonFont">The button font.</param>
			/// <param name="position">The position.</param>
			/// <param name="size">The size.</param>
			/// <param name="borderColor">Color of the border.</param>
			/// <param name="borderSize">Size of the border.</param>
			Button(std::string buttonText, sf::Color textColor, sf::Font* buttonFont, sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color borderColor, float borderSize);

			/// <summary>
			/// Finalizes an instance of the <see cref="Button"/> class.
			/// </summary>
			~Button();

			/// <summary>
			/// Updates this instance.
			/// </summary>
			void Update();

			/// <summary>
			/// Handles the input.
			/// </summary>
			/// <param name="drawer">The drawer.</param>
			/// <param name="event">The event.</param>
			void HandleInput(Drawer* drawer, sf::Event event);

			/// <summary>
			/// Draws the Button with the specified drawer.
			/// </summary>
			/// <param name="drawer">The drawer.</param>
			void Draw(Drawer* drawer);
			
			/// <summary>
			/// Gets the text of the button.
			/// </summary>
			/// <returns>The text of the button.</returns>
			std::string GetText();

			/// <summary>
			/// Sets the text.
			/// </summary>
			/// <param name="text">The text.</param>
			void SetText(std::string text);

			/// <summary>
			/// Gets the color of the text.
			/// </summary>
			/// <returns>The color of the text.</returns>
			sf::Color GetTextColor();

			/// <summary>
			/// Sets the color of the text.
			/// </summary>
			/// <param name="color">The color.</param>
			void SetTextColor(sf::Color color);

			/// <summary>
			/// A boolean for determining if the button is enabled.
			/// </summary>
			bool IsEnabled;
		private:			
			/// <summary>
			/// The offset for the text. This is needed or position calculations don't go right.
			/// </summary>
			const int* textOffset = new int(12);
			
			/// <summary>
			/// The mouse position of the previous frame.
			/// </summary>
			sf::Vector2i oldMousePosition;

			/// <summary>
			/// The font to use for the text in the button.
			/// </summary>
			sf::Font* font;

			/// <summary>
			/// The text on the button.
			/// </summary>
			sf::Text text;
		};
	}
}
#endif