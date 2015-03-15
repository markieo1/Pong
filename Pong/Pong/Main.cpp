#include "Game.h"

int main()
{
	Game g = Game("Marco's Pong", 1024, 768, GameStates::MAINMENU);
	g.Run();

	return 0;
}