#include "Game.h"

void Game::Run()
{
	Initialize();

	sf::Clock deltaClock;
	while (drawer.GameWindow->isOpen() && GameStateHandler.GetCurrentState() != GameStates::QUIT)
	{
		float deltaTime = deltaClock.restart().asSeconds();

		HandleInput();

		Update(deltaTime);

		Draw();
	}
}

void Game::Update(float deltaTime)
{
	switch (GameStateHandler.GetCurrentState())
	{
		case GameStates::MAINMENU:
		{
			break;
		}

		case GameStates::NEWGAME:
		{
			ScoreHandler::player1Score = 0;
			ScoreHandler::player2Score = 0;
			ball.position = sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
			ball.circle.setPosition(ball.position);
			ball.velocity = sf::Vector2f(0.f, 0.f);
			text.setString(sf::String("Press enter to launch the ball."));
			text.setPosition(SCREEN_WIDTH / 2.f - text.getGlobalBounds().width / 2, 30.f);
			break;
		}

		case GameStates::PAUSED:
		{
			text.setString(sf::String("Press enter to continue!"));
			text.setPosition(SCREEN_WIDTH / 2.f - text.getGlobalBounds().width / 2, 30.f);
			break;
		}

		case GameStates::INGAME:
		default:
		{
			int lastPlayer1Score = ScoreHandler::player1Score;
			int lastPlayer2Score = ScoreHandler::player2Score;
			player1.Update(deltaTime);
			player2.Update(deltaTime);

			ball.Update(deltaTime, &player1, &player2);

			if (lastPlayer1Score != ScoreHandler::player1Score || lastPlayer2Score != ScoreHandler::player2Score) //Scored on a side
			{
				ball.position = sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
				ball.velocity = sf::Vector2f(0.f, 0.f);
				ball.circle.setPosition(ball.position);
				GameStateHandler.SetState(GameStates::PAUSED);
			}

			text.setString(sf::String(std::to_string(ScoreHandler::player1Score) + " - " + std::to_string(ScoreHandler::player2Score)));
			text.setPosition(SCREEN_WIDTH / 2.f - text.getGlobalBounds().width / 2, 30.f);

			break;
		}
	}
}

void Game::Draw()
{
	drawer.GameWindow->clear();
	switch (GameStateHandler.GetCurrentState())
	{
		case GameStates::MAINMENU:
		{
			gui->draw();
			break;
		}

		case GameStates::NEWGAME:
		case GameStates::PAUSED:
		case GameStates::INGAME:
		default:
		{
			ball.Draw(&drawer);
			player1.Draw(&drawer);
			player2.Draw(&drawer);
			drawer.GameWindow->draw(text);
			break;
		}
	}

	drawer.GameWindow->display();
}

void Game::HandleInput()
{
	sf::Event event;
	while (drawer.GameWindow->pollEvent(event))
	{
		gui->handleEvent(event);
		if (event.type == sf::Event::Closed)
		{
			drawer.GameWindow->close();
		}
	}

	if (drawer.GameWindow->hasFocus())
	{
		switch (GameStateHandler.GetCurrentState())
		{
			case GameStates::MAINMENU:
			{
				tgui::Callback callback;
				while (gui->pollCallback(callback))
				{
					if (callback.id == 1)
					{
						GameStateHandler.SetState(GameStates::NEWGAME);
					}
				}
				break;
			}

			case GameStates::NEWGAME:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					GameStateHandler.SetState(GameStates::INGAME);

					if (ball.velocity == sf::Vector2f(0.f, 0.f))
					{
						ball.position = sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
						ball.circle.setPosition(ball.position);
						ball.velocity = sf::Vector2f(BallMoveSpeed, BallMoveSpeed); // Make it possible random direction, at the moment always to the right
					}
				}
				break;
			}

			case GameStates::PAUSED:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					GameStateHandler.SetState(GameStates::INGAME);

					if (ball.velocity == sf::Vector2f(0.f, 0.f))
					{
						ball.position = sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
						ball.circle.setPosition(ball.position);
						ball.velocity = sf::Vector2f(BallMoveSpeed, BallMoveSpeed); // Make it possible random direction, at the moment always to the right
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					GameStateHandler.SetState(GameStates::NEWGAME);
				}
				break;
			}

			case GameStates::INGAME:
			default:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::P)) // Check if escape or p key is pressed.
				{
					GameStateHandler.SetState(GameStates::PAUSED);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					GameStateHandler.SetState(GameStates::NEWGAME);
				}

				player1.HandleInput();
				player2.HandleInput();
				break;
			}
		}
	}
}

void Game::Initialize()
{
	GameStateHandler = GameStateFactory(START_STATE);

	drawer = PongEngine::Drawer();
	drawer.Init(WINDOW_TITLE, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, sf::Style::Close);

	gui = new tgui::Gui(*drawer.GameWindow);

	font.loadFromFile("./Debug/arial.ttf");
	text.setFont(font);
	gui->setGlobalFont(font);

	tgui::Button::Ptr button(*gui);
	button->load("D:/Downloads/TGUI-0.6.7/TGUI-0.6.7/widgets/Black.conf");
	button->setSize(100, 100);
	button->setPosition(100, 100);
	button->setText("lol");
	button->bindCallback(tgui::Button::LeftMouseClicked);
	button->setCallbackId(1);

	ball = Ball(sf::Vector2f(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f), sf::Vector2f(0.f, .0f), 10, sf::Color::White, BallMoveSpeed);
	player1 = Player(sf::Vector2f(40.f, ((SCREEN_HEIGHT / 2) - 200.f)), sf::Vector2f(0.f, 0.f), sf::Vector2f(20.f, 200.f), sf::Color::White, PlayerMoveSpeed); // Uses default up and down keys (w and s);
	player2 = Player(sf::Vector2f((SCREEN_WIDTH - 60.f), ((SCREEN_HEIGHT / 2) - 200.f)), sf::Vector2f(0.f, 0.f), sf::Vector2f(20.f, 200.f), sf::Color::White, PlayerMoveSpeed, sf::Keyboard::Up, sf::Keyboard::Down);
}