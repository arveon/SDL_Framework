#include "Game.h"

using namespace sdlframework;

//your game initialisation logic
game::game()
{
	srand(time(NULL));
}

//your game destructor
game::~game()
{

}

//game initialisation
void sdlframework::game::init()
{
	left_click = false;

	change_color();
	cur_color = RGB{ 0, 0, 0 };
}

//called every frame
void sdlframework::game::input()
{
	static bool left_down = false;
	
	//reading events such as windows X button pressed
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			quit_game = true;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)//reading mouse events to determine when the click occurs
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				left_down = true;
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (left_down)
					std::cout << "Clicked" << std::endl;
				left_down = false;
			}
		}
	}

}

//updates every frame until false is returned
bool game::update(Uint32 delta_time)
{
	bool game_running = true;

	//increase or decrease current color depending on the destination color
	if (cur_color.R < dest_color.R)
		cur_color.R++;
	else if (cur_color.R > dest_color.R)
		cur_color.R--;
	if (cur_color.G < dest_color.G)
		cur_color.G++;
	else if (cur_color.G > dest_color.G)
		cur_color.G--;
	if (cur_color.B < dest_color.B)
		cur_color.B++;
	else if (cur_color.B > dest_color.B)
		cur_color.B--;

	//if destination color reached, generate new destination color
	if (cur_color.R == dest_color.R && cur_color.G == dest_color.G && cur_color.B == dest_color.B)
		change_color();

	SDL_Delay(15);

	//std::cout << "R:" << cur_color.R << " G:" << cur_color.G << " B:" << cur_color.B << std::endl;
	//std::cout << "DR:" << dest_color.R << " DG:" << dest_color.G << " DB:" << dest_color.B << std::endl;


	if (quit_game == true)
		game_running = false;
	return game_running;
}

//draws every frame
void game::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, cur_color.R, cur_color.G, cur_color.B, 255);
	
	SDL_RenderClear(renderer);

	//put your draw code here




	SDL_RenderPresent(renderer);
}

//customly created method
void game::change_color()
{
	dest_color = RGB{ rand()%255, rand()%255, rand()%255 };
	std::cout << "color changed" << std::endl;
	std::cout << "DR:" << dest_color.R << " DG:" << dest_color.G << " DB:" << dest_color.B << std::endl;
}
