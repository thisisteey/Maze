#include "../headers/maze.h"

/**
 * free_map_data - Deallocates memory used by the 2D map
 * @maze_map: pointer to the MazeMap_t data structure
 * Return: void
*/
void free_map_data(MazeMap_t *maze_map)
{
	int row_idx;

	for (row_idx = 0 ; row_idx < maze_map->num_rows ; row_idx++)
		free(maze_map->map_layout[row_idx]);
	free(maze_map->map_layout);
}
