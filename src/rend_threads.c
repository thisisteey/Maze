#include "../inc/maze.h"

/**
 * transmit_viewport - Renders and displays the contents of the renderer
 * @sdl: pointer to the SDL_Instance data structure
 * Return: void
*/
void transmit_viewport(SDL_Instance *sdl)
{
	REND_COLOR_BLACK(sdl->sdl_renderer);
	SDL_SetRenderDrawBlendMode(sdl->sdl_renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderPresent(sdl->sdl_renderer);
	SDL_RenderClear(sdl->sdl_renderer);
}

/**
 * handle_thread - Handles rendering in a separate thread
 * @thrd_ptr: void pointer to the ThreadData data structure
 * Return: integer indicating thread status
*/
int handle_thread(void *thrd_ptr)
{
	ThreadData *thrdt = thrd_ptr;
	Uint64 strcnt, endcnt;
	double rendTimeMs;

	while (*(thrdt->exit_flag) == 0)
	{
		strcnt = SDL_GetPerformanceCounter();
		plot_textured_sky(thrdt->sdl, thrdt->maze_map);
		plot_untextured_floor(thrdt->sdl);
		raycast(thrdt->sdl, thrdt->player_info, thrdt->maze_map,
			thrdt->map_flag);
		plot_weapon(thrdt->sdl, thrdt->maze_map);
		if (*(thrdt->map_flag) != 0)
		{
			plot_mazemap(thrdt->sdl, thrdt->maze_map);
			render_player(thrdt->sdl, thrdt->player_info);
		}
		transmit_viewport(thrdt->sdl);
		endcnt = SDL_GetPerformanceCounter();
		rendTimeMs = (endcnt - strcnt) / SDL_GetPerformanceCounter() * 1000;
		SDL_Delay(floor(16.666 - rendTimeMs));
	}
	return (0);
}
