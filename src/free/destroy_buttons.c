/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** buttons
*/

#include "defender.h"

void destroy_buttons(game_t *game)
{
    for (int i = 0; i != 9; i++) {
        sfSprite_destroy(game->button[i]->sprite);
        free(game->button[i]);
    }
    free(game->button);
}
