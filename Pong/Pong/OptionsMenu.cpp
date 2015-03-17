#include "OptionsMenu.h"

OptionsMenu::OptionsMenu() : drawer(new PongEngine::Drawer())
{}

OptionsMenu::OptionsMenu(PongEngine::Drawer& drawer, sf::Font* textFont) : drawer(&drawer)
{
	resolutionTextField = PongEngine::GUI::TextField(textFont, sf::Vector2f(100.f, 100.f), sf::Vector2f(300.0f, 30.0f));
	resolutionTextField.SetText("1024x768");
}

void OptionsMenu::Update()
{
	resolutionTextField.Update();
}

void OptionsMenu::Draw()
{
	resolutionTextField.Draw(drawer);
}