#ifndef GAME_H
#define GAME_H
#include "Drawer.h"
#include "Player.h"
#include "Ball.h"
#include "ScoreHandler.h"
#include "GameStateFactory.h"

/// <summary>
/// A class that handles everything in the game.
/// </summary>
class Game
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Game"/> class.
	/// </summary>
	Game() : WINDOW_TITLE("My Game created with SFML."), SCREEN_WIDTH(100), SCREEN_HEIGHT(100), START_STATE(GameStates::PAUSED)
	{};

	/// <summary>
	/// Initializes a new instance of the <see cref="Game"/> class.
	/// </summary>
	/// <param name="title">The title.</param>
	/// <param name="screenWidth">Width of the window to create.</param>
	/// <param name="screenHeight">Height of the window to create..</param>
	/// <param name="startState">The start state.</param>
	Game(std::string title, int screenWidth, int screenHeight, GameStates startState) : WINDOW_TITLE(title), SCREEN_WIDTH(screenWidth), SCREEN_HEIGHT(screenHeight), START_STATE(startState)
	{};

	/// <summary>
	/// Finalizes an instance of the <see cref="Game"/> class.
	/// </summary>
	~Game() {};

	/// <summary>
	/// Runs this instance.
	/// </summary>
	void Run();

	/// <summary>
	/// Initializes this instance.
	/// </summary>
	void Initialize();

	/// <summary>
	/// Handles the input.
	/// </summary>
	void HandleInput();

	/// <summary>
	/// Draws this instance.
	/// </summary>
	void Draw();

	/// <summary>
	/// Updates the specified delta time.
	/// </summary>
	/// <param name="deltaTime">The delta time.</param>
	void Update(float deltaTime);

	/// <summary>
	/// The window title.
	/// </summary>
	const std::string WINDOW_TITLE;

	/// <summary>
	/// The screen width.
	/// </summary>
	const int SCREEN_WIDTH;

	/// <summary>
	/// The screen height.
	/// </summary>
	const int SCREEN_HEIGHT;

	/// <summary>
	/// The player move speed.
	/// </summary>
	const float PlayerMoveSpeed = 200.f;

	/// <summary>
	/// The ball move speed.
	/// </summary>
	const float BallMoveSpeed = 300.f;

	/// <summary>
	/// The start state.
	/// </summary>
	const GameStates START_STATE;
private:
	/// <summary>
	/// The drawer.
	/// </summary>
	PongEngine::Drawer drawer;

	/// <summary>
	/// The ball.
	/// </summary>
	Ball ball;

	/// <summary>
	/// The player1.
	/// </summary>
	Player player1;

	/// <summary>
	/// The player2.
	/// </summary>
	Player player2;

	/// <summary>
	/// The game state handler.
	/// </summary>
	GameStateFactory GameStateHandler;

	/// <summary>
	/// The font to use to draw text.
	/// </summary>
	sf::Font font;

	/// <summary>
	/// The text to draw.
	/// </summary>
	sf::Text text;
};

#endif