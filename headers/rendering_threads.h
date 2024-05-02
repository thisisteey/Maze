#ifndef REND_THREAD_H
#define REND_THREAD_H

/*
 * Description:
 * This file contains rendering and thread handling functions of the Maze game
 */

/* Rendering and Thread Handling functions */
void transmit_viewport(SDL_Instance *sdl);
int handle_thread(void *thrd_ptr);

#endif
