/*
** EPITECH PROJECT, 2020
** free
** File description:
** game resources
*/

#include "../include/my.h"
#include "../include/defender.h"

void destroy_game(game_t *game)
{
    if (game->core)
        destroy_core(game);
    if (game->enemy)
        destroy_enemies(game);
    if (game->tower && game->tower2)
        destroy_towers(game);
    if (game->base)
        free(game->base);
    if (game->cursor)
        free(game->cursor);
    if (game->button)
        destroy_buttons(game);
    if (game->particle)
        destroy_particles(game);
}
