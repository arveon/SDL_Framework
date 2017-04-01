#include "System.h"

using namespace sdlframework;
void system::init_system()
{
	sdl_manager::init();
}

void system::game_loop()
{
	time.init();
	bool gameGoing = true;
	while (gameGoing)
	{
		time.update();
		gameGoing = game.update(time.get_delta_time());
		game.draw(sdl_manager::get_renderer());
		game.input();

		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				gameGoing = false;
			}
		}
	}
}

void system::cleanup()
{
}

system::system()
{
}


system::~system()
{
}
