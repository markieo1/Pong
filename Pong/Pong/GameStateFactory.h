#ifndef GAMESTATEFACTORY_H
#define GAMESTATEFACTORY_H

#include "GameStates.h"

/// <summary>
/// A class to handle GameStates.
/// </summary>
class GameStateFactory
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="GameStateFactory"/> class.
	/// </summary>
	GameStateFactory();

	/// <summary>
	/// Initializes a new instance of the <see cref="GameStateFactory"/> class.
	/// </summary>
	/// <param name="startState">The start state.</param>
	GameStateFactory(GameStates startState);

	/// <summary>
	/// Finalizes an instance of the <see cref="GameStateFactory"/> class.
	/// </summary>
	~GameStateFactory() {};

	/// <summary>
	/// Gets the state of the current.
	/// </summary>
	/// <returns></returns>
	GameStates GetCurrentState();

	/// <summary>
	/// Sets the state.
	/// </summary>
	/// <param name="state">The state.</param>
	void SetState(GameStates state);
private:
	/// <summary>
	/// The current state.
	/// </summary>
	GameStates currentState;
};
#endif