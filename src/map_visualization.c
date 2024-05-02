#include "../headers/maze.h"

/**
 * plot_mazemap - Renders a 2D map on the SDL window
 * @sdl: pointer to the SDL_Instance data structure
 * @maze_map: pointer to the MazeMap_t data structure
 * Return: void
*/
void plot_mazemap(SDL_Instance *sdl, MazeMap_t *maze_map)
{
	int row_idx, col_idx;
	SDL_Rect cell = {0, 0, GRID_SIZE, GRID_SIZE};

	for (row_idx = 0 ; row_idx < maze_map->num_rows ; row_idx++)
	{
		for (col_idx = 0 ; col_idx < maze_map->num_columns ; col_idx++)
		{
			cell.x = (col_idx << 4) + MAP_MARGIN;
			cell.y = (row_idx << 4) + MAP_MARGIN;
			if (maze_map->map_layout[row_idx][col_idx] == '0')
			{
				REND_COLOR(sdl->sdl_renderer, 255, 255, 255, 100);
				SDL_RenderFillRect(sdl->sdl_renderer, &cell);
			}
			else
			{
				REND_COLOR(sdl->sdl_renderer, 0, 0, 0, 150);
				SDL_RenderFillRect(sdl->sdl_renderer, &cell);
			}
		}
	}
}

/**
 * plot_textured_sky - Renders a textured sky to the SDL window
 * @sdl: pointer to the SDL_Instance data structure
 * @maze_map: pointer to the MazeMap_t data structure
 * Return: void
*/
void plot_textured_sky(SDL_Instance *sdl, MazeMap_t *maze_map)
{
	SDL_Rect sky_dome = {0, 0, SCREEN_WIDTH, (SCREEN_HEIGHT >> 1)};
	SDL_Surface *sky_surface;

	if (sdl->sky_texture == NULL)
	{
		sky_surface = SDL_LoadBMP("images/sky.bmp");
		if (sky_surface == NULL)
		{
			printf("Sky Surface Error: %s", SDL_GetError());
			free_map_data(maze_map);
			close_sdl(sdl);
			exit(EXIT_FAILURE);
		}
		sdl->sky_texture = SDL_CreateTextureFromSurface(sdl->sdl_renderer,
			sky_surface);
		SDL_FreeSurface(sky_surface);
	}
	SDL_RenderCopy(sdl->sdl_renderer, sdl->sky_texture, NULL, &sky_dome);
}

/**
 * plot_untextured_sky - Renders an untextured ceiling to the SDL window
 * @sdl: pointer to the SDL_Instance data structure
 * Return: void
*/
void plot_untextured_sky(SDL_Instance *sdl)
{
	SDL_Rect sky_dome = {0, 0, SCREEN_WIDTH, (SCREEN_HEIGHT >> 1)};

	REND_COLOR(sdl->sdl_renderer, 25, 181, 254, 255);
	SDL_RenderFillRect(sdl->sdl_renderer, &sky_dome);
}

/**
 * plot_untextured_floor - Renders an untextured floor to the SDL window
 * @sdl: pointer to the SDL_Instance data structure
 * Return: void
*/
void plot_untextured_floor(SDL_Instance *sdl)
{
	double floor_offset = (SCREEN_HEIGHT >> 1);
	SDL_Rect floor_area;

	floor_area.x = 0;
	floor_area.y = floor_offset;
	floor_area.w = SCREEN_WIDTH;
	floor_area.h = (SCREEN_HEIGHT >> 1);

	REND_COLOR(sdl->sdl_renderer, 52, 140, 49, 255);
	SDL_RenderFillRect(sdl->sdl_renderer, &floor_area);
}

/**
 * set_wall_tones - Assigns colour for painting walls based on side
 * @color_ptr: pointer to the color data structure
 * @side: side in which the ary is hitting
 * Return: void
*/
void set_wall_tones(SDL_Color *color_ptr, int side)
{
	SDL_Color vert_color = {112, 112, 112, 255};
	SDL_Color horz_color = {96, 96, 96, 150};

	if (side == ORIENT_UP_DOWN)
		*color_ptr = vert_color;
	else
		*color_ptr = horz_color;
}
