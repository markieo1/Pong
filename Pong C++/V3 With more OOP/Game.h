#ifndef __Game__
#define __Game__

#include "SDL.h"
class Game
{
public:
	Game() {};
	~Game() {};

	bool init(const char* title, int xpos, int ypos, int width,
		int height, int flags);
	//render
	void render();
	void update();
	void handleEvents();
	void clean();

	//a function to acces the private running variable
	bool running()
	{
		return m_bRunning;
	}

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};
#endif