#include "Time.h"

using namespace sdlframework;
void time::init()
{
	elapsed_time = SDL_GetTicks();
}

void time::update()
{
	elapsed_time = run_time - SDL_GetTicks();
	run_time += elapsed_time;
}
