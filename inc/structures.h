#ifndef MAZE_STRUCT_H
#define MAZE_STRUCT_H

/*
 * Description:
 * This header file contains defined structures for rendering, player,
 * map, lines and multi-threading.
 */

/**
 * struct SDL_Instance - Structure containing SDL global variables
 * @sdl_window: pointer to the SDL window for displaying the game
 * @sdl_renderer: pointer to the SDL renderer for rendering graphics
 * @sky_texture: pointer tothe texture representing the sky texture
 * @wall_surface: pointer to the surface for rending walls
 * @wall_texture: pointer to the texture for representing walls
 * @weapon_texture: pointer to the texture representing player's weapon
 */
typedef struct SDL_Instance
{
	SDL_Window *sdl_window;
	SDL_Renderer *sdl_renderer;
	SDL_Texture *sky_texture;
	SDL_Surface *wall_surface;
	SDL_Texture *wall_texture;
	SDL_Texture *weapon_texture;
} SDL_Instance;

/**
 * struct PlayerInfo - Structure containing player info in the game
 * @position: represents the player's position on the screen
 * @current_angle: represents the current viewing angle of the player
 */
typedef struct PlayerInfo
{
	SDL_Rect position;
	float current_angle;
} PlayerInfo;

/**
 * struct MazeMap - Structure containing game's map layout
 * @map_layout: pointer to the 2D array representing the map
 * @num_rows: represents the number of rows in the map
 * @num_columns: represents the number of columns in the map
 */
typedef struct MazeMap
{
	char **map_layout;
	int num_rows;
	int num_columns;
} MazeMap_t;

/**
 * struct LineSegment - Structure containing line segment
 * @start_point: represents starting point of the line segment
 * @end_point: represents the ending point of the line segment
 */
typedef struct LineSegment
{
	SDL_Point start_point;
	SDL_Point end_point;
} LineSegment;

/**
 * struct ThreadData - Structure containing data for multithreading in the game
 * @sdl: pointer to the structure of the SDL_Instance
 * @player_info: pointer to the structure of the PlayerInfo
 * @maze_map: pointer to the structure of the MazeMap
 * @map_flag: pointer indicating the map status
 * @exit_flag: pointer indicating program exit status
 */
typedef struct ThreadData
{
	SDL_Instance *sdl;
	MazeMap_t *maze_map;
	struct PlayerInfo *player_info;
	SDL_bool *map_flag;
	int *exit_flag;
} ThreadData;

#endif
