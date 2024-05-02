#ifndef PLAYER_H
#define PLAYER_H

/*
 * Description:
 * This file contains player handling and player movement functions
 * of the Maze game
 */

/* Player Handling functions */
void render_player(SDL_Instance *sdl, PlayerInfo *player_info);
void skid_player(PlayerInfo *player_info);
void plot_weapon(SDL_Instance *sdl, MazeMap_t *maze_map);
void collision_sensor(PlayerInfo *player_info, MazeMap_t *maze_map);

/* Player movement functions */
void mouse_movement(PlayerInfo *player_info, SDL_Point *cursor);
SDL_Point move_player(PlayerInfo *player_info);

#endif
