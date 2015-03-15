#include "GameStateFactory.h"

GameStateFactory::GameStateFactory()
{
	currentState = GameStates::MAINMENU;
}

GameStateFactory::GameStateFactory(GameStates startState)
{
	currentState = startState;
}

void GameStateFactory::SetState(GameStates state)
{
	currentState = state;
}

GameStates GameStateFactory::GetCurrentState()
{
	return this->currentState;
}