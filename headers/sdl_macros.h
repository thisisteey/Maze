#ifndef SDL_MACROS_H
#define SDL_MACROS_H

/*
 * Description:
 * This header file contains macros and constants related to SDL rendering
 * and various game parameters.
 */


/* SDL Color Renderer Macros */
#define REND_COLOR_WHITE(ren) SDL_SetRenderDrawColor(ren, 255, 255, 255, 255)
#define REND_COLOR_BLACK(ren) SDL_SetRenderDrawColor(ren, 0, 0, 0, 255)
#define REND_COLOR_YELLOW(ren) SDL_SetRenderDrawColor(ren, 255, 255, 0, 255)
#define REND_COLOR_GREEN(ren) SDL_SetRenderDrawColor(ren, 0, 255, 0, 255)
#define REND_COLOR_BLUE(ren) SDL_SetRenderDrawColor(ren, 0, 0, 255, 255)
#define REND_COLOR(ren, r, g, b, a) SDL_SetRenderDrawColor(ren, r, g, b, a)

/* Boolean Constants */
#define TRUE 1
#define FALSE 0

/* Screen Dimensions */
#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 900

/* Map and Player Constants */
#define MAP_MARGIN 20
#define PLAYER_WIDTH 10
#define ORIENT_UP_DOWN 1
#define ORIENT_LEFT_RIGHT 2
#define GRID_SIZE 16

/* Window Title */
#define WINDOW_TITLE "Maze: Navigate the Unknown"

/* Field of View */
#define FOV 60

/* Math Utilities */
#define RADIAN(x) (x * (M_PI / 180.0))
#define ROTATION_MAGNITUDE 1

/* Movement Constants */
#define MOVE_SPEED 2
#define MAX_DRAW_DISTANCE 1024

#endif
