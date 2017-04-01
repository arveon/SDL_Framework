#include "System.h"

using namespace sdlframework;
void system::init_system()
{
	sdl_manager::init();
}

void system::game_loop()
{
	time.update();
	while (game.update())
	{
		game.draw();
		game.input();
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
