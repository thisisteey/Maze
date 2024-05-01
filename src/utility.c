#include "../inc/maze.h"

/**
 * check_arr - Checks if a value exists in an array
 * @arr_val: value to find in the array
 * @arr: pointer to the array to check
 * @arr_lent: length of the array to be checked
 * Return: 1 if value is found in array or 0 otherwise
*/
int check_arr(char arr_val, char *arr, unsigned int arr_lent)
{
	unsigned int idx;

	for (idx = 0 ; idx < arr_lent ; idx++)
	{
		if (arr[idx] == arr_val)
			return (1);
	}
	return (0);
}

/**
 * str_concat - Merger two strings together
 * @dest_str: pointer to the destination string
 * @src_str: pointer to the source string to append
 * Return: new string that has been merged
*/
char *str_concat(const char *dest_str, const char *src_str)
{
	char *newstr = NULL;

	newstr = malloc(strlen(dest_str) + strlen(src_str) + 1);
	if (newstr == NULL)
		return (NULL);
	strcpy(newstr, dest_str);
	strcat(newstr, src_str);
	return (newstr);
}

/**
 * slope_region - Calculates the quadrant of an angle
 * @angle: the angle to calculate its quadrant
 * @exp_angle: pointer to the angle to the rangle between (0-360)
 * Return: the quadrant to which the angle belongs between (0-3)
*/
int slope_region(int angle, int *exp_angle)
{
	int region;

	angle %= 360;
	if (angle < 0)
		angle += 360;
	region = (angle / 90) % (4 + 1);
	*exp_angle = angle;

	return (region);
}
