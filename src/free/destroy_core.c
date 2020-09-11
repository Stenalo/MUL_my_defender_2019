/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** window
*/

#include "defender.h"

void destroy_core(game_t *game)
{
    sfRenderWindow_destroy(game->core->window);
    free(game->core);
}