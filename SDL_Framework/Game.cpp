#include "Game.h"

using namespace sdlframework;

//your game initialisation logic
game::game()
{
	
}

//your game destructor
game::~game()
{

}

void sdlframework::game::init()
{
}

void sdlframework::game::input()
{
}

//updates every frame until false is returned
bool game::update(Uint32 delta_time)
{
	bool game_running = true;

	std::cout << delta_time << std::endl;

	return game_running;
}

//draws every frame
void game::draw(SDL_Renderer* renderer)
{


}
