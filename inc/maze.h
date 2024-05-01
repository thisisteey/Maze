#ifndef MAZE_H
#define MAZE_H

/*
 * Description:
 * Header file for SDL-based Maze game with rendering and event handling.
 */

/*
 * SDL Libraries:
 * Includes SDL and SDL_thread headers based on the operating system
 */
#ifdef LINUX
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#elif defined(MAC)
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#else
#include <SDL.h>
#include <SDL_thread.h>
#endif

/*
 * Standard Libraries:
 * Includes standard C libraries for file I/O memory management,
 * string manipulation and math operations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Custom Headers:
 * Includes header files containing structures, macros and prototpye
 * for the Maze game components.
 */
#include "structures.h"
#include "sdl_macros.h"
#include "file_utilities.h"
#include "player.h"
#include "map_raycasting.h"
#include "rendering_threads.h"
#include "sdl_functions.h"

#endif
