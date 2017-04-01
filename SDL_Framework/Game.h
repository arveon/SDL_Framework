#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

namespace sdlframework
{
	class game
	{
	private:

	public:
		void init();
		void input();
		bool update();
		void draw();

		game();
		~game();
	};
}

