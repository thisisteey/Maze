#include "../headers/maze.h"

/**
 * open_file - Initiates the opening of a file
 * @filenm: pointer to the name of the file
 * Return: the file pointer to the opened file
*/
FILE *open_file(char *filenm)
{
	FILE *fileptr = NULL;

	fileptr = fopen(filenm, "r");
	if (fileptr == NULL)
	{
		fprintf(stderr, "File Error: Can't open file %s\n", filenm);
		exit(EXIT_FAILURE);
	}
	return (fileptr);
}

/**
 * read_file - Reads a file content and constructs a MazeMap_t data structure
 * @fileptr: pointer to the input file
 * Return: a MazeMap_t containing mazemap data read from the file
*/
MazeMap_t read_file(FILE *fileptr)
{
	size_t lncount = 0;
	char *content = NULL;
	char *lncpy = NULL;
	MazeMap_t maze_map = {NULL, 0, 0};
	unsigned int lnidx = 0, lnlent = 0;

	maze_map.num_rows = count_lines(fileptr);
	maze_map.map_layout = malloc(sizeof(char *) * maze_map.num_rows);
	while ((getline(&content, &lncount, fileptr)) != -1)
	{
		lncpy = strtok(strdup(content), "\n");
		if (lnlent == 0)
		{
			maze_map.num_columns = strlen(lncpy);
			lnlent++;
		}
		authz_line(maze_map.num_columns, lncpy, fileptr, (lnidx + 1));
		maze_map.map_layout[lnidx] = lncpy;
		lnidx++;
	}
	free(content);
	fseek(fileptr, 0, SEEK_SET);

	return (maze_map);
}

/**
 * close_file - Closes a previously opened file
 * @fileptr: pointer to the file to be closed
 * Return: void
*/
void close_file(FILE *fileptr)
{
	if (fileptr != NULL)
		fclose(fileptr);
}
