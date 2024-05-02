#include "../headers/maze.h"

/**
 * raycast - Shoots rays to render 3D scene on 2D map
 * @sdl: pointer to the SDL_Instance data structure
 * @player_info: pointer to the PlayerInfo data structure
 * @maze_map: pointer to the MazeMap_t data structure
 * @map_flag: pointer to the Boolean indicating mazemap display status
 * Return: void
*/
void raycast(SDL_Instance *sdl, PlayerInfo *player_info,
	MazeMap_t *maze_map, SDL_bool *map_flag)
{
	SDL_Point point, plyctr;
	double idx, deg = (player_info->current_angle - (FOV / 2.0));
	double ray_ang;
	double raylent = 0.0;
	double expdist = 0.0;
	SDL_Color sd_color = {0, 0, 0, 0};
	int side;
	double curr_ang = (deg - FOV);

	plyctr.x = player_info->position.x + (player_info->position.w / 2);
	plyctr.y = player_info->position.y + (player_info->position.h / 2);
	ray_ang = ((FOV) / (SCREEN_WIDTH * 1.0));
	for (idx = 0 ; idx < SCREEN_WIDTH ; idx++)
	{
		point = check_intersection(&plyctr, curr_ang, *maze_map, &raylent,
			&side);
		set_wall_tones(&sd_color, side);
		if (*map_flag)
		{
			REND_COLOR_GREEN(sdl->sdl_renderer);
			SDL_RenderDrawLine(sdl->sdl_renderer, plyctr.x, plyctr.y, point.x, point.y);
		}
		expdist = remove_distortion(player_info, raylent, curr_ang);
		plot_walls(sdl, expdist, idx, sd_color);
		curr_ang += ray_ang;
	}
}

/**
 * check_intersection - Checks if ray intersects with walls
 * @ctr: pointer to the point from the the player's center
 * @rot_angle: angle rotation for the ray
 * @maze_map: pointer to the MazeMap_t data structure
 * @raylent: pointer to store the ray's resulting length
 * @side: indicates the side of ray's intersection
 * Return: SDL_Point with the cordinates of the ray
*/
SDL_Point check_intersection(SDL_Point *ctr, double rot_angle,
	MazeMap_t maze_map, double *raylent, int *side)
{
	SDL_Point point;
	SDL_bool walls_intersect = SDL_FALSE;
	int rowidx, colidx;
	SDL_Rect wallRect;
	LineSegment LineSegment = {{0, 0}, {0, 0}};
	double opp, adj, hypt;

	point.x = ctr->x;
	point.y = ctr->y;
	wallRect.x = 0;
	wallRect.y = 0;
	wallRect.w = GRID_SIZE;
	wallRect.h = GRID_SIZE;
	point = rotate_point(&point, ctr->x, ctr->y, RADIAN(rot_angle),
		MAX_DRAW_DISTANCE);
	for (rowidx = 0 ; rowidx < maze_map.num_rows ; rowidx++)
		for (colidx = 0 ; colidx < maze_map.num_columns ; colidx++)
		{
			if (maze_map.map_layout[rowidx][colidx] == '0')
				continue;
			wallRect.x = (colidx << 4) + MAP_MARGIN;
			wallRect.y = (rowidx << 4) + MAP_MARGIN;
			LineSegment.start_point = *ctr;
			LineSegment.end_point = point;
			walls_intersect = SDL_IntersectRectAndLine(
				&wallRect, &LineSegment.start_point.x, &LineSegment.start_point.y,
				&LineSegment.end_point.x, &LineSegment.end_point.y);
			if (walls_intersect == SDL_TRUE)
			{
				*side = check_lines(wallRect, ctr, &LineSegment.start_point);
				adj = LineSegment.start_point.x - ctr->x;
				opp = LineSegment.start_point.y - ctr->y;
				hypt = sqrt((pow(opp, 2.0) + pow(adj, 2.0)));
				point = *ctr;
				point = rotate_point(&point, ctr->x, ctr->y, RADIAN(rot_angle), hypt);
				*raylent = hypt;
			}
		}
	return (point);
}

/**
 * remove_distortion - Corrects distortion in ray length
 * @player_info: pointer to the PlayerInfo data structure
 * @raylent: length of ray from player to wall
 * @ray_angle: angle of ray relative to player's view
 * Return: corrected ray length to mitigate distortion
*/
double remove_distortion(PlayerInfo *player_info, double raylent,
	double ray_angle)
{
	double distortedRaylent = raylent;
	double correctedRaylent = 0.0;
	double anglediff = (player_info->current_angle - (FOV / 2.0));

	correctedRaylent = distortedRaylent *
		cos(RADIAN((ray_angle - (anglediff - FOV / 2.0))));
	return (correctedRaylent);
}

/**
 * plot_walls - Projects and renders walls on the SDL renderer
 * @sdl: pointer to the SDL_Instance data structure
 * @raylent: length of ray from player to wall
 * @ray_idx: current screen column to draw the wall
 * @wall_color: pointer to the SDL_Color data structure
 * Return: void
*/
void plot_walls(SDL_Instance *sdl, double raylent, int ray_idx,
	SDL_Color wall_color)
{
	int projectionDistance = (SCREEN_WIDTH / 2) / (tan(RADIAN((FOV / 2))));
	double wallheight = ceil((SCREEN_HEIGHT / (raylent * 1.0)) *
		(projectionDistance >> 6));
	double walldrawstart = (SCREEN_HEIGHT / 2.0) - (wallheight / 2.0);

	plot_textured_walls(sdl, wallheight, ray_idx, walldrawstart,
		wall_color.a);
}
