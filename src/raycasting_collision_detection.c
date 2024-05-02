#include "../headers/maze.h"

/**
 * check_lines - Check if lines intersects with the sides of a rectangle
 * @wall: the rectangle to check for intersection
 * @strtpnt: pointer to the lines starting point
 * @endpnt: pointer to the lines ending point
 * Return: 1 if intersection occurs at rectangle top or bottom, otherwise 2
*/
int check_lines(SDL_Rect wall, SDL_Point *strtpnt, SDL_Point *endpnt)
{
	LineSegment rectTop, rectBottom, ray;
	SDL_Point interpnt = {0, 0};

	rectTop.start_point.x = wall.x;
	rectTop.start_point.y = wall.y;
	rectTop.end_point.x = wall.x + wall.w;
	rectTop.end_point.y = wall.y;

	rectBottom.start_point.x = wall.x;
	rectBottom.start_point.y = wall.y + wall.h;
	rectBottom.end_point.x = wall.x + wall.w;
	rectBottom.end_point.y = wall.y + wall.h;

	ray.start_point = *strtpnt;
	ray.end_point = *endpnt;

	if (line_seg_cross(&rectTop, &ray, &interpnt))
		return (ORIENT_UP_DOWN);
	else if (line_seg_cross(&rectBottom, &ray, &interpnt))
		return (ORIENT_UP_DOWN);
	return (ORIENT_LEFT_RIGHT);
}

/**
 * line_seg_cross - Determines if two line segments intersects
 * @fstln: pointer to the first line segment in the LineSegment data structure
 * @scdln: pointer to the second line segment in the LineSegment data structure
 * @pntptr: pointer to the SDL_Point data structure
 * Return: 1 if intersection occurs, otherwise 0
*/
int line_seg_cross(LineSegment *fstln, LineSegment *scdln, SDL_Point *pntptr)
{
	int denom, fstnum, scdnum, paramA, paramB;

	/* for more info visit http://paulbourke.net/geometry/pointlineplane/ */

	denom = (
		scdln->end_point.y - scdln->start_point.y) *
		(fstln->end_point.x - fstln->start_point.x) -
		(scdln->end_point.x - scdln->start_point.x) *
		(fstln->end_point.y - fstln->start_point.y);

	fstnum = (
		scdln->end_point.x - scdln->start_point.x) *
		(fstln->start_point.y - scdln->start_point.y) -
		(scdln->end_point.y - scdln->start_point.y) *
		(fstln->start_point.x - scdln->start_point.x);

	scdnum = (
		fstln->end_point.x - fstln->start_point.x) *
		(fstln->start_point.y - scdln->start_point.y) -
		(fstln->end_point.y - fstln->start_point.y) *
		(fstln->start_point.x - scdln->start_point.x);

	if (denom == 0)
		return (0);
	paramA = (fstnum << 14) / denom;
	paramB = (scdnum << 14) / denom;

	if (paramA >= 0 && paramA <= (1 << 14) && paramB >= 0 && paramB <= (1 << 14))
	{
		pntptr->x = fstln->start_point.x + ((paramA * (fstln->end_point.x -
			fstln->start_point.x)) >> 14);
		pntptr->y = fstln->start_point.y + ((paramA * (fstln->end_point.y -
			fstln->start_point.y)) >> 14);
		return (1);
	}
	return (0);
}
