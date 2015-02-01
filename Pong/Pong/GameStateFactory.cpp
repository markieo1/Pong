#include "GameStateFactory.h"

GameStateFactory::GameStateFactory()
{
	currentState = INGAME;
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
	return currentState;
}