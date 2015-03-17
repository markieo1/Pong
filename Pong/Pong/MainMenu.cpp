#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu() : drawer(new PongEngine::Drawer())
{}

MainMenu::MainMenu(PongEngine::Drawer& drawer, sf::Font* buttonFont) : drawer(&drawer)
{
	newGameButton = PongEngine::GUI::Button("New Game", sf::Color::Red, buttonFont, sf::Vector2f(drawer.GameWindow->getSize().x / 2.0f - 150.0f, drawer.GameWindow->getSize().y / 2.0f - 250.0f), sf::Vector2f(300.0f, 100.0f));
	optionsButton = PongEngine::GUI::Button("Options", sf::Color::Red, buttonFont, sf::Vector2f(drawer.GameWindow->getSize().x / 2.0f - 150.0f, drawer.GameWindow->getSize().y / 2.0f - 100.0f), sf::Vector2f(300.0f, 100.0f));
	exitGameButton = PongEngine::GUI::Button("Exit Game", sf::Color::Red, buttonFont, sf::Vector2f(drawer.GameWindow->getSize().x / 2.0f - 150.0f, drawer.GameWindow->getSize().y / 2.0f + 50.0f), sf::Vector2f(300.0f, 100.0f));


	using std::placeholders::_1;
	newGameButton.OnMouseClickEvent = std::bind(&MainMenu::NewGameButtonClick, this, _1);
	exitGameButton.OnMouseClickEvent = std::bind(&MainMenu::ExitGameButtonClick, this, _1);

	newGameButton.OnMouseEnterEvent = std::bind(&MainMenu::ButtonOnMouseEnter, this, _1);
	optionsButton.OnMouseEnterEvent = std::bind(&MainMenu::ButtonOnMouseEnter, this, _1);
	exitGameButton.OnMouseEnterEvent = std::bind(&MainMenu::ButtonOnMouseEnter, this, _1);
	optionsButton.IsEnabled = false;
	newGameButton.OnMouseLeaveEvent = std::bind(&MainMenu::ButtonOnMouseLeave, this, _1);
	optionsButton.OnMouseLeaveEvent = std::bind(&MainMenu::ButtonOnMouseLeave, this, _1);
	exitGameButton.OnMouseLeaveEvent = std::bind(&MainMenu::ButtonOnMouseLeave, this, _1);
	Update();
}

void MainMenu::Update()
{
	newGameButton.Update();
	optionsButton.Update();
	exitGameButton.Update();
}

void MainMenu::HandleInput(sf::Event event)
{
	newGameButton.HandleInput(drawer, event);
	optionsButton.HandleInput(drawer, event);
	exitGameButton.HandleInput(drawer, event);
}

void MainMenu::Draw()
{
	newGameButton.Draw(drawer);
	optionsButton.Draw(drawer);
	exitGameButton.Draw(drawer);
}

void MainMenu::ShowHoverIndicator(PongEngine::GUI::Button* button, float size, bool ScaleUp)
{
	if (ScaleUp)
	{
		float xPos = button->GetPosition().x - size / 2;
		float yPos = button->GetPosition().y - size / 2;

		float width = button->GetSize().x + size;
		float height = button->GetSize().y + size;

		button->SetPosition(xPos, yPos);
		button->SetSize(width, height);
	}
	else
	{
		float xPos = button->GetPosition().x + size / 2;
		float yPos = button->GetPosition().y + size / 2;

		float width = button->GetSize().x - size;
		float height = button->GetSize().y - size;

		button->SetPosition(xPos, yPos);
		button->SetSize(width, height);
	}
}

void MainMenu::ButtonOnMouseEnter(PongEngine::GUI::Button* button)
{
	ShowHoverIndicator(button, 10.0, true);
}

void MainMenu::ButtonOnMouseLeave(PongEngine::GUI::Button* button)
{
	ShowHoverIndicator(button, 10.0, false);
}

void MainMenu::NewGameButtonClick(PongEngine::GUI::Button* button)
{
	Game::CurrentState = GameStates::NEWGAME;
}

void MainMenu::ExitGameButtonClick(PongEngine::GUI::Button* button)
{
	Game::CurrentState = GameStates::QUIT;
}