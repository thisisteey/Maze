#include "../inc/maze.h"

/**
 * render_player - Renders the player as a filled rectangle
 * @sdl: pointer to the SDL_Instance data structure
 * @player_info: pointer to the PlayerInfo data structure
 * Return: void
*/
void render_player(SDL_Instance *sdl, PlayerInfo *player_info)
{
	REND_COLOR_YELLOW(sdl->sdl_renderer);
	SDL_RenderFillRect(sdl->sdl_renderer, &player_info->position);
}

/**
 * skid_player - Adjusts player position on collision with calls
 * @player_info: pointer to the PlayerInfo data structure
 * Return: void
*/
void skid_player(PlayerInfo *player_info)
{
	int player_ang;

	slope_region((player_info->current_angle - (FOV / 2.0)), &player_ang);

	if (player_ang > 300 || player_ang < 60)
	{
		player_info->position.x++;
		player_info->position.y++;
	}
	else if (player_ang > 60 && player_ang < 170)
	{
		player_info->position.x--;
		player_info->position.y--;
	}
	else if (player_ang > 170 && player_ang < 235)
	{
		player_info->position.x++;
		player_info->position.y--;
	}
	else if (player_ang > 235 && player_ang < 300)
	{
		player_info->position.x++;
		player_info->position.y++;
	}
}

/**
 * plot_weapon - Renders the gun image on the SDL window
 * @sdl: pointer to the SDL_Instance data structure
 * @maze_map: pointer to the MazeMap_t data structure
 * Return: void
*/
void plot_weapon(SDL_Instance *sdl, MazeMap_t *maze_map)
{
	SDL_Rect gun_position = {700, 450, 700, 450};
	SDL_Surface *gun_surface;

	if (sdl->weapon_texture == NULL)
	{
		gun_surface = SDL_LoadBMP("images/weapon.bmp");
		if (gun_surface == NULL)
		{
			printf("Weapon Surface Error: %s", SDL_GetError());
			free_map_data(maze_map);
			close_sdl(sdl);
			exit(EXIT_FAILURE);
		}
		sdl->weapon_texture = SDL_CreateTextureFromSurface(sdl->sdl_renderer,
			gun_surface);
		SDL_FreeSurface(gun_surface);
	}
	SDL_RenderCopy(sdl->sdl_renderer, sdl->weapon_texture, NULL, &gun_position);
}

/**
 * collision_sensor - Identifies collisions between the player and walls
 * @player_info: pointer to the PlayerInfo data structure
 * @maze_map: pointer to the MazeMap_t data structure
 * Return: void
*/
void collision_sensor(PlayerInfo *player_info, MazeMap_t *maze_map)
{
	SDL_Rect wall = {0, 0, GRID_SIZE, GRID_SIZE};
	int row_idx, col_idx;
	int wall_margin = 5;
	int player_dims = player_info->position.w + wall_margin;
	SDL_Rect player_box;

	player_box.x = player_info->position.x - (wall_margin / 2);
	player_box.y = player_info->position.y - (wall_margin / 2);
	player_box.w = player_dims;
	player_box.h = player_dims;
	for (row_idx = 0 ; row_idx < maze_map->num_rows ; row_idx++)
	{
		for (col_idx = 0 ; col_idx < maze_map->num_columns ; col_idx++)
		{
			if (maze_map->map_layout[row_idx][col_idx] == '0')
				continue;
			wall.x = (col_idx << 4) + MAP_MARGIN;
			wall.y = (row_idx << 4) + MAP_MARGIN;
			if (SDL_HasIntersection(&player_box, &wall))
				skid_player(player_info);
		}
	}
}
