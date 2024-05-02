#include "../headers/maze.h"

/**
 * main - Entry point of the Maze program
 * @argc: number of command line arguments
 * @argv: double pointer to an array of strings passed to the command-line args
 * Return: 0 on success, or exit with status failure
*/
int main(int argc, char **argv)
{
	SDL_Instance sdl = {NULL, NULL, NULL, NULL, NULL, NULL};
	MazeMap_t maze_map;
	char *map_dir;

	if (argc < 2)
	{
		printf("Usage: %s 'map_dir'", argv[0]);
		exit(EXIT_FAILURE);
	}
	map_dir = str_concat("maps/", argv[1]);
	maze_map = handle_file(map_dir);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL Initialization Error! SDL_Error:%s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	get_window(WINDOW_TITLE, &sdl);
	get_renderer(&sdl);
	game_loop(&sdl, &maze_map);
	free_map_data(&maze_map);
	close_sdl(&sdl);

	return (0);
}
