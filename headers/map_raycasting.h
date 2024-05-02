#ifndef MAP_RAYCAST_H
#define MAP_RAYCAST_H

/*
 * Description:
 * This header file contains map visualization, map management and
 * raycasting algorithm functions
 */

/* Map visualization functions */
void plot_mazemap(SDL_Instance *sdl, MazeMap_t *maze_map);
void plot_textured_sky(SDL_Instance *sdl, MazeMap_t *maze_map);
void plot_untextured_sky(SDL_Instance *sdl);
void plot_untextured_floor(SDL_Instance *sdl);
void set_wall_tones(SDL_Color *color_ptr, int side);

/* Map management function(s) */
void free_map_data(MazeMap_t *maze_map);

/* Raycasting Algorithm functions */
void raycast(SDL_Instance *sdl, PlayerInfo *player_info,
	MazeMap_t *maze_map, SDL_bool *map_flag);
SDL_Point check_intersection(SDL_Point *ctr, double rot_angle,
	MazeMap_t maze_map, double *raylent, int *side);
double remove_distortion(PlayerInfo *player_info, double raylent,
	double ray_angle);
void plot_walls(SDL_Instance *sdl, double raylent, int ray_idx,
	SDL_Color wall_color);

/* Raycasting Collision Detection functions */
int check_lines(SDL_Rect wall, SDL_Point *strtpnt, SDL_Point *endpnt);
int line_seg_cross(LineSegment *fstln, LineSegment *scdln, SDL_Point *pntptr);

/* Raycasting Texture Rendering function(s) */
void plot_textured_walls(SDL_Instance *sdl, double wallhgt, int currcol,
	int strt_axis, uint8_t alpha);

#endif
