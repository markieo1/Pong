#include "GUIRectangle.h"
namespace PongEngine
{
	namespace GUI
	{
		GuiRectangle::GuiRectangle()
		{
			rectangle = sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
			rectangle.setPosition(sf::Vector2f(0.0f,0.0f));
			rectangle.setFillColor(sf::Color::White);
			rectangle.setOutlineColor(sf::Color::Red);
			rectangle.setOutlineThickness(2.0f);
		}

		GuiRectangle::GuiRectangle(sf::Vector2f position, sf::Vector2f size)
		{
			rectangle = sf::RectangleShape(size);
			rectangle.setPosition(position);
			rectangle.setFillColor(sf::Color::White);
			rectangle.setOutlineColor(sf::Color::Red);
			rectangle.setOutlineThickness(2.0f);
		}

		GuiRectangle::GuiRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color borderColor, float borderSize)
		{
			rectangle = sf::RectangleShape(size);
			rectangle.setPosition(position);
			rectangle.setFillColor(fillColor);
			rectangle.setOutlineColor(borderColor);
			rectangle.setOutlineThickness(borderSize);
		}

		sf::Vector2f GuiRectangle::GetPosition()
		{
			return rectangle.getPosition();
		}

		void GuiRectangle::SetXPosition(float x)
		{
			SetPosition(sf::Vector2f(x, GetPosition().y));
		}

		void GuiRectangle::SetYPosition(float y)
		{
			SetPosition(sf::Vector2f(GetPosition().x, y));
		}

		void GuiRectangle::SetPosition(float x, float y)
		{
			rectangle.setPosition(x, y);
		}

		void GuiRectangle::SetPosition(sf::Vector2f position)
		{
			rectangle.setPosition(position.x, position.y);
		}

		sf::Vector2f GuiRectangle::GetSize()
		{
			return rectangle.getSize();
		}

		void GuiRectangle::SetWidth(float width)
		{
			SetSize(width, GetSize().y);
		}

		void GuiRectangle::SetHeight(float height)
		{
			SetSize(GetSize().x, height);
		}

		void GuiRectangle::SetSize(float width, float height)
		{
			rectangle.setSize(sf::Vector2f(width, height));
		}

		void GuiRectangle::SetSize(sf::Vector2f size)
		{
			rectangle.setSize(size);
		}

		sf::Color GuiRectangle::GetBorderColor()
		{
			return rectangle.getOutlineColor();
		}

		void GuiRectangle::SetBorderColor(sf::Color color)
		{
			rectangle.setOutlineColor(color);
		}

		sf::Color GuiRectangle::GetBackgroundColor()
		{
			return rectangle.getFillColor();
		}

		void GuiRectangle::SetBackgroundColor(sf::Color color)
		{
			rectangle.setFillColor(color);
		}

		float GuiRectangle::GetBorderSize()
		{
			return rectangle.getOutlineThickness();
		}

		void GuiRectangle::SetBorderSize(float size)
		{
			rectangle.setOutlineThickness(size);
		}
	}
}