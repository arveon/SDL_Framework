#include "System.h"

using namespace sdlframework;
void system::init_system()
{
	sdl_manager::init();
}

void system::game_loop()
{
	time.init();
	game.init();
	bool gameGoing = true;
	while (gameGoing)
	{
		time.update();
		game.input();
		gameGoing = game.update(time.get_delta_time());
		game.draw(sdl_manager::get_renderer());
	}
}

//called before the program exits
void system::cleanup()
{
}




/*currently not used for anything*/
system::system()
{
}


system::~system()
{
}
