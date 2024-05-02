#include "../headers/maze.h"

/**
 * mouse_movement - Tracks mouse cordinates and adjusts player rotation
 * @player_info: pointer to the PlayerInfo data structure
 * @cursor: pointer to the SDL_Point storing mouse cordinates
 * Return: void
*/
void mouse_movement(PlayerInfo *player_info, SDL_Point *cursor)
{
	int mouse_x_pos = cursor->x;
	int x_movement = 0;

	SDL_GetMouseState(&cursor->x, &cursor->y);
	x_movement = cursor->x - mouse_x_pos;
	if (x_movement < 0)
		player_info->current_angle -= ROTATION_MAGNITUDE;
	else
		player_info->current_angle += ROTATION_MAGNITUDE;
}

/**
 * move_player - Moves player position based the direction faced
 * @player_info: pointer to the PlayerInfo data structure
 * Return: SDL_Point with displacement distance
*/
SDL_Point move_player(PlayerInfo *player_info)
{
	SDL_Point vector = {0, 0};
	double degree_rad = player_info->current_angle;

	vector.x = cos(RADIAN((90 - (degree_rad - (FOV / 2))))) * MOVE_SPEED;
	vector.y = sin(RADIAN((90 - (degree_rad - (FOV / 2))))) * MOVE_SPEED;

	return (vector);
}
