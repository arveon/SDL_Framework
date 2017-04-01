#pragma once
#include <SDL.h>

namespace sdlframework
{
	static class time
	{
	private:
		Uint32 elapsed_time;
		Uint32 run_time;

	public:
		void init();
		void update();

		float get_delta_time() { return elapsed_time; }
		float get_run_time() { return run_time; }
	};
}

