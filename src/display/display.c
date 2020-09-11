/*
** EPITECH PROJECT, 2020
** display
** File description:
** game
*/

#include "../include/my.h"
#include "../include/defender.h"

void game_display(game_t *game)
{
    sfRenderWindow_display(game->core->window);
    sfRenderWindow_clear(game->core->window, sfBlack);
}
