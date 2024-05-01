#include "../inc/maze.h"

/**
 * count_lines - Count the lines within a file
 * @fileptr: pointer to the file to count
 * Return: number of line in the file
*/
int count_lines(FILE *fileptr)
{
	char filechar;
	int lncount = 0;

	while (!feof(fileptr))
	{
		filechar = fgetc(fileptr);
		if (filechar == '\n')
		{
			lncount++;
		}
	}
	fseek(fileptr, 0, SEEK_SET);

	return (lncount + 1);
}

/**
 * authz_line - Examine line contents for errors and authenticate
 * @maxln_cnt: maximum permissible line length
 * @line: pointer to the to be checked
 * @fileptr: pointer to the file to check its line content
 * @curr_ln: current line number been assessed
 * Return: void
*/
void authz_line(int maxln_cnt, char *line, FILE *fileptr, int curr_ln)
{
	char allowed_chars[] = {'0', '1'};
	int idx;
	unsigned int lnlent = strlen(line);

	if (line == NULL)
		return;
	if (lnlent != (unsigned int)maxln_cnt)
	{
		free(line);
		close_file(fileptr);
		printf("Error line No. %d: The columns should be equal.\n", curr_ln);
		exit(EXIT_FAILURE);
	}
	for (idx = 0 ; idx < maxln_cnt ; idx++)
	{
		if ((check_arr(line[idx], allowed_chars, maxln_cnt)) == 0)
		{
			printf("Error Line No. %d: Invalid map values found.\n", curr_ln);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * handle_file - Handles file operation functions
 * @filenm: pointer to the file to handle
 * Return: MazeMap_t data structure containing map info
*/
MazeMap_t handle_file(char *filenm)
{
	FILE *fileptr = NULL;
	MazeMap_t maze_map;

	fileptr = open_file(filenm);
	maze_map = read_file(fileptr);
	close_file(fileptr);

	return (maze_map);
}
