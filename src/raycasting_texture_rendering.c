#include "../headers/maze.h"

/**
 * plot_textured_walls - Renders textured wall to the SDL window
 * @sdl: pointer to the SDL_Instance data structure
 * @wallhgt: height of the wall to draw
 * @currcol: current column on the screen to draw the texture
 * @strt_axis: starting cordinate of the column to start drawing
 * @pixctrl: conrols the pixel for the sides
 * Return: void
*/
void plot_textured_walls(SDL_Instance *sdl, double wallhgt, int currcol,
	int strt_axis, uint8_t pixctrl)
{
	SDL_Rect destrect = {0, 0, 1, 64}, srcrect, wallarea;
	int blitres;
	SDL_Surface *surface;

	srcrect.x = currcol % 64;
	srcrect.y = 0;
	srcrect.w = 1;
	srcrect.h = 64;
	surface = SDL_CreateRGBSurface(0, 1, 64, 32, 0, 0, 0, 0);
	wallarea.x = currcol;
	wallarea.y = strt_axis;
	wallarea.w = 1;
	wallarea.h = wallhgt;

	sdl->wall_surface = (sdl->wall_surface == NULL) ?
		SDL_LoadBMP("images/wall.bmp") : sdl->wall_surface;
	if (sdl->wall_surface == NULL)
	{
		printf("Wall Surface Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_UnlockSurface(surface);
	blitres = SDL_BlitSurface(sdl->wall_surface, &srcrect, surface, &destrect);
	SDL_LockSurface(surface);
	if (blitres < 0)
	{
		printf("Blit Surface Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	sdl->wall_texture = (sdl->wall_texture == NULL) ? SDL_CreateTextureFromSurface
		(sdl->sdl_renderer, surface) : sdl->wall_texture;
	if (sdl->wall_texture == NULL)
	{
		printf("Wall Texture Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_UpdateTexture(sdl->wall_texture, NULL, surface->pixels, surface->pitch);
	SDL_SetTextureColorMod(sdl->wall_texture, pixctrl, pixctrl, pixctrl);
	SDL_RenderCopy(sdl->sdl_renderer, sdl->wall_texture, NULL, &wallarea);
	SDL_FreeSurface(surface);
}
