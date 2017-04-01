#pragma once
#include "Game.h"
#include "Time.h"
#include "sdl_manager.h"

namespace sdlframework
{
	class system
	{
	private:
		time time;
		game game;

	public:
		void init_system();
		void game_loop();
		void cleanup();

		system();
		~system();
	};
}

