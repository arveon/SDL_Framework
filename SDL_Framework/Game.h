#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <iostream>

namespace sdlframework
{
	class game
	{
	private:

	public:
		void init();
		void input();
		bool update(Uint32 deltaTime);
		void draw(SDL_Renderer* renderer);

		game();
		~game();
	};
}

