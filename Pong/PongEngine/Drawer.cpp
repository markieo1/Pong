#include "Drawer.h"

namespace PongEngine
{
	sf::Vector2u Drawer::windowSize = sf::Vector2u();

	void Drawer::Init(std::string title, int xPos, int yPos, int width, int height, sf::Uint32 style)
	{
		CreateWindow(title, xPos, yPos, width, height, style);
		windowSize = GameWindow->getSize();
	}

	void Drawer::CreateWindow(std::string title, int xPos, int yPos, int width, int height, sf::Uint32 style)
	{
		if (style == sf::Style::Fullscreen)
		{
			xPos = 0;
			yPos = 0;
		}

		GameWindow = new sf::RenderWindow(sf::VideoMode(width, height), title, style);
		//GameWindow->setVerticalSyncEnabled(true);
		GameWindow->setPosition(sf::Vector2i(xPos, yPos));
	}

	sf::Texture* Drawer::LoadTexture(std::string fileName)
	{
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(fileName);
		return texture;
	}
}