#include "../headers/maze.h"

/**
 * sdl_err - Prints sdl errors
 * Return: void
*/
void sdl_err(void)
{
	printf("An SDL error has occured:%s\n", SDL_GetError());
}

/**
 * rotate_point - Performs rotation of an SDL_Point around a given center
 * @point: pointer to the SDL_Point data structure
 * @xctr: x-cordinate of the center of rotation
 * @yctr: y-cordinate of the center of rotation
 * @rotang: angle of rotation in degrees (converted to radians)
 * @ray_sz: length of the casted ray which increases upon collision
 * Return: a new SDL_Point after rotation
*/
SDL_Point rotate_point(const SDL_Point *point, float xctr, float yctr,
	float rotang, float ray_sz)
{
	SDL_Point newpnt = {0, 0};

	newpnt.x = ((point->x - xctr) * cos(rotang) - (((point->y - ray_sz) - yctr) *
						sin(rotang))) + xctr;
	newpnt.y = ((point->x - xctr) * sin(rotang) + (((point->y - ray_sz) - yctr) *
						cos(rotang))) + yctr;
	/*
	 * for more understanding visit
	 * https://danceswithcode.net/engineeringnotes/rotations_in
	 * _2d/rotations_in_2d.html
	 */
	return (newpnt);
}

/**
 * game_loop - Manages the game's event loop and listens for SDL events
 * @sdl: pointer to the SDL_Instance data structure
 * @maze_map: pointer to the MazeMap_t data structure
 * Return: void
*/
void game_loop(SDL_Instance *sdl, MazeMap_t *maze_map)
{
	int exit_flag = 0;
	SDL_Event evnt;
	PlayerInfo player_info = {{80, 70, PLAYER_WIDTH, PLAYER_WIDTH}, (FOV * 2.5)};
	SDL_Point cursor = {0, 0};
	SDL_bool map_flag = SDL_TRUE;
	SDL_Thread *threadID;
	ThreadData thrdt;

	thrdt.sdl = sdl;
	thrdt.maze_map = maze_map;
	thrdt.player_info = &player_info;
	thrdt.map_flag = &map_flag;
	thrdt.exit_flag = &exit_flag;
	threadID = NULL;
	threadID = SDL_CreateThread(handle_thread, "RenderingThread", &thrdt);

	while (!exit_flag)
	{
		handle_events(&exit_flag, &evnt, &player_info, &cursor, &map_flag);
		collision_sensor(&player_info, maze_map);
	}
	SDL_WaitThread(threadID, NULL);
}

/**
 * handle_events - Listens and manages SDL events in the game
 * @exit_flag: pointer to the interger indicating the status of the SDL loop
 * @evnt: pointer to the SDL_Event data structure
 * @player_info: pointer to the PlayerInfo data structure
 * @cursor: pointer to an SDL_Point indicating mouse positions
 * @map_flag: pointer to the boolean indicating map display
 * Return: void
*/
void handle_events(int *exit_flag, SDL_Event *evnt, PlayerInfo *player_info,
	SDL_Point *cursor, SDL_bool *map_flag)
{
	SDL_Point vector = {0, 0};

	vector = move_player(player_info);
	while (SDL_PollEvent(evnt) != 0)
	{
		if (evnt->type == SDL_QUIT)
			*exit_flag = 1;
		if (evnt->type == SDL_MOUSEMOTION)
			mouse_movement(player_info, cursor);
		switch (evnt->key.keysym.sym)
		{
			case SDLK_ESCAPE:
				*exit_flag = 1;
				break;
			case SDLK_w:
				player_info->position.x += vector.x;
				player_info->position.y -= vector.y;
				break;
			case SDLK_s:
				player_info->position.x -= vector.x;
				player_info->position.y += vector.y;
				break;
			case SDLK_a:
				player_info->current_angle -= ROTATION_MAGNITUDE;
				break;
			case SDLK_d:
				player_info->current_angle += ROTATION_MAGNITUDE;
				break;
			case SDLK_m:
				*map_flag = SDL_FALSE;
				break;
			case SDLK_n:
				*map_flag = SDL_TRUE;
				break;
			default:
				break;
		}
	}
}
