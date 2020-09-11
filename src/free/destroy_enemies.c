/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** enemies
*/

#include "defender.h"

void destroy_enemies(game_t *game)
{
    for (int i = 0; i != ENEMY_MAX; i++)
        free(game->enemy[i]);
    free(game->enemy);
}
