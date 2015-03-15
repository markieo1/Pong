#include "Button.h"
#include <iostream>

namespace PongEngine
{
	namespace GUI
	{
		Button::Button()
		{
			IsEnabled = true;
			rectangle = sf::RectangleShape(sf::Vector2f(100, 100));
			rectangle.setPosition(100, 100);
			rectangle.setFillColor(sf::Color::Red);
			rectangle.setOutlineColor(sf::Color::White);
			rectangle.setOutlineThickness(10);

			text = sf::Text();
		}

		Button::Button(std::string buttonText, sf::Color textColor, sf::Font* buttonFont, sf::Vector2f position, sf::Vector2f size)
		{
			IsEnabled = true;
			rectangle = sf::RectangleShape(size);
			rectangle.setPosition(position);

			font = buttonFont;
			text = sf::Text(buttonText, *font, 75);
			text.setPosition(position);
			text.setColor(textColor);
		}

		Button::Button(std::string buttonText, sf::Color textColor, sf::Font* buttonFont, sf::Vector2f position, sf::Vector2f size, sf::Color borderColor, float borderSize)
		{
			IsEnabled = true;
			rectangle = sf::RectangleShape(size);
			rectangle.setOutlineThickness(borderSize);
			rectangle.setOutlineColor(borderColor);
			rectangle.setPosition(position);
			font = buttonFont;
			text = sf::Text(buttonText, *font, 75);
			text.setPosition(position);
			text.setColor(textColor);
		}

		Button::~Button() {}

		void Button::Update()
		{
			float textWidth = text.getLocalBounds().width + *textOffset;
			float textHeight = font->getLineSpacing(text.getCharacterSize()) / 2 + text.getLocalBounds().height;
			float fontScaleW = rectangle.getSize().x / textWidth;
			if (fontScaleW > 1.0f)
			{
				//This means the font size is too low.
				//It gets blurry.
				//Therefore we let it stay at its normal size.
				fontScaleW = 1.0f;
			}

			float fontScaleH = rectangle.getSize().y / textHeight;
			if (fontScaleH > 1.0f)
			{
				//This means the font size is too low.
				//It gets blurry.
				//Therefore we let it stay at its normal size.
				fontScaleH = 1.0f;
			}
			sf::FloatRect test = rectangle.getLocalBounds();
			text.setScale(fontScaleW, fontScaleH);
		}

		void Button::HandleInput(Drawer* drawer, sf::Event event)
		{
			if (IsEnabled) {
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i mousePos = sf::Mouse::getPosition(*drawer->GameWindow);
						if (rectangle.Contains(mousePos))
						{
							//Call the MouseClick
							if (OnMouseClickEvent != NULL)
							{
								OnMouseClickEvent(this);
							}
						}
					}
				}
			}

			sf::Vector2i mousePoint = sf::Mouse::getPosition(*drawer->GameWindow);
			if (rectangle.Contains(mousePoint))
			{
				//Call on MouseHover
				if (OnMouseHoverEvent != NULL)
				{
					OnMouseHoverEvent(this);
				}

				if (!rectangle.Contains(oldMousePosition))
				{
					//Call on MouseEnter
					if (OnMouseEnterEvent != NULL)
					{
						OnMouseEnterEvent(this);
					}
				}
			}
			else if (rectangle.Contains(oldMousePosition))
			{
				//Call on MouseLeave
				if (OnMouseLeaveEvent != NULL)
				{
					OnMouseLeaveEvent(this);
				}
			}

			oldMousePosition = mousePoint;
		}

		void Button::Draw(Drawer* drawer)
		{
			drawer->GameWindow->draw(rectangle);
			drawer->GameWindow->draw(text);

			if (!IsEnabled)
			{
				sf::RectangleShape rectangleTinted = sf::RectangleShape(rectangle.getSize());
				rectangleTinted.setPosition(rectangle.getPosition());
				rectangleTinted.setFillColor(sf::Color(128, 128, 128, 200));
				drawer->GameWindow->draw(rectangleTinted);
			}
		}

		sf::Vector2f Button::GetPosition()
		{
			return rectangle.getPosition();
		}

		void Button::SetXPosition(float x)
		{
			SetPosition(sf::Vector2f(x, GetPosition().y));
		}

		void Button::SetYPosition(float y)
		{
			SetPosition(sf::Vector2f(GetPosition().x, y));
		}

		void Button::SetPosition(float x, float y)
		{
			rectangle.setPosition(x, y);
			text.setPosition(x, y);
		}

		void Button::SetPosition(sf::Vector2f position)
		{
			rectangle.setPosition(position.x, position.y);
			text.setPosition(position);
		}

		sf::Vector2f Button::GetSize()
		{
			return rectangle.getSize();
		}

		void Button::SetWidth(float width)
		{
			SetSize(width, GetSize().y);
		}

		void Button::SetHeight(float height)
		{
			SetSize(GetSize().x, height);
		}

		void Button::SetSize(float width, float height)
		{
			rectangle.setSize(sf::Vector2f(width, height));
		}

		void Button::SetSize(sf::Vector2f size)
		{
			rectangle.setSize(size);
		}

		std::string Button::GetText()
		{
			return text.getString().toAnsiString();
		}

		void Button::SetText(std::string text)
		{
			this->text.setString(text);
		}

		sf::Color Button::GetTextColor()
		{
			return text.getColor();
		}

		void Button::SetTextColor(sf::Color color)
		{
			this->text.setColor(color);
		}

		sf::Color Button::GetBorderColor()
		{
			return rectangle.getOutlineColor();
		}

		void Button::SetBorderColor(sf::Color color)
		{
			rectangle.setOutlineColor(color);
		}

		sf::Color Button::GetBackgroundColor()
		{
			return rectangle.getFillColor();
		}

		void Button::SetBackgroundColor(sf::Color color)
		{
			rectangle.setFillColor(color);
		}

		float Button::GetBorderSize()
		{
			return rectangle.getOutlineThickness();
		}

		void Button::SetBorderSize(float size)
		{
			rectangle.setOutlineThickness(size);
		}
	}
}