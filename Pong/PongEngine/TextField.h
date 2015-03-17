#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "Drawer.h"
namespace PongEngine
{
	namespace GUI
	{
		class TextField
		{
		public:
			TextField();
			TextField(sf::Font* font, sf::Vector2f position, sf::Vector2f size);
			~TextField();

			/// <summary>
			/// Updates this instance.
			/// </summary>
			void Update();

			/// <summary>
			/// Draws the Button with the specified drawer.
			/// </summary>
			/// <param name="drawer">The drawer.</param>
			void Draw(Drawer* drawer);

			void SetText(std::string text);
		private:
			/// <summary>
			/// The offset for the text. This is needed or position calculations don't go right.
			/// </summary>
			const int* textOffset = new int(12);
			sf::RectangleShape rectangle;
			sf::Font* font;
			sf::Text Text;
		};
	}
}

#endif