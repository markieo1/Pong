#include "Game.h"

int main()
{
	Game g = Game("Marco's Pong", 1280, 720, GameStates::INGAME);
	g.Run();

	return 0;
}