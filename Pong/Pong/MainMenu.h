#ifndef MAINMENU_H
#define MAINMENU_H

#include "Drawer.h"
#include "Button.h"
#include <iostream>
class MainMenu
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="MainMenu"/> class.
	/// Don't use it. Use the one with the reference to the real drawer.
	/// </summary>
	MainMenu();

	MainMenu(PongEngine::Drawer& drawer, sf::Font* buttonFont);
	~MainMenu() {};

	void Update();
	void HandleInput(sf::Event event);
	void Draw();
private:
	PongEngine::Drawer* drawer;

	PongEngine::GUI::Button newGameButton;
	PongEngine::GUI::Button optionsButton;
	PongEngine::GUI::Button exitGameButton;

	void ShowHoverIndicator(PongEngine::GUI::Button* button, int size, bool ScaleUp);

	void ButtonOnMouseEnter(PongEngine::GUI::Button* button);
	void ButtonOnMouseLeave(PongEngine::GUI::Button* button);
	void NewGameButtonClick(PongEngine::GUI::Button* button);
	void ExitGameButtonClick(PongEngine::GUI::Button* button);
};

#endif