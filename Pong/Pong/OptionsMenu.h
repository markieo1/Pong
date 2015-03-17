#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "Drawer.h"
#include "TextField.h"
class OptionsMenu
{
public:
	OptionsMenu();

	OptionsMenu(PongEngine::Drawer& drawer, sf::Font* buttonFont);
	~OptionsMenu() {};

	void Update();
	void Draw();
private:
	PongEngine::Drawer* drawer;

	PongEngine::GUI::TextField resolutionTextField;
};

#endif