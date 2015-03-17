#include "TextField.h"
namespace PongEngine
{
	namespace GUI
	{
		TextField::TextField()
		{

		}

		TextField::TextField(sf::Font* font, sf::Vector2f position, sf::Vector2f size)
		{
			this->font = font;
			Text = sf::Text(sf::String(), *font, 30);
			Text.setColor(sf::Color::Red);
			Text.setOrigin(Text.getLocalBounds().width / 2.0f, Text.getLocalBounds().height / 2.0f);
			rectangle = sf::RectangleShape(size);
			rectangle.setPosition(position);
			rectangle.setOutlineColor(sf::Color::Yellow);
			rectangle.setOutlineThickness(2.f);
		}

		TextField::~TextField() {}

		void TextField::Update()
		{
			float rectangleWidth = rectangle.getSize().x;
			float rectangleHeight = rectangle.getSize().y ;

			float textWidth = Text.getLocalBounds().width + *textOffset;
			float textHeight = font->getLineSpacing(Text.getCharacterSize()) / 2 + Text.getLocalBounds().height;
			float fontScaleW = rectangleWidth / textWidth;
			if (fontScaleW > 1.0f)
			{
				//This means the font size is too low.
				//It gets blurry.
				//Therefore we let it stay at its normal size.
				fontScaleW = 1.0f;
			}

			float fontScaleH = rectangleHeight / textHeight;
			if (fontScaleH > 1.0f)
			{
				//This means the font size is too low.
				//It gets blurry.
				//Therefore we let it stay at its normal size.
				fontScaleH = 1.0f;
			}

			textWidth *= fontScaleW;
			textHeight *= fontScaleH;

			float posX = (rectangleWidth / 2.0f) - (textWidth / 2) + rectangle.getPosition().x;
			float posY = (rectangleHeight / 2.0f) - (textHeight / 2) + rectangle.getPosition().y;
			Text.setPosition(posX, posY);
			Text.setScale(fontScaleW, fontScaleH);
		}

		void TextField::Draw(Drawer* drawer)
		{
			drawer->GameWindow->draw(rectangle);
			drawer->GameWindow->draw(Text);
		}

		void TextField::SetText(std::string text)
		{
			Text.setString(text);
		}
	}
}