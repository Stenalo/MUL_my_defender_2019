/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** towers
*/

#include "defender.h"

void destroy_towers(game_t *game)
{
    for (int i = 0; i != 49; i++)
        free(game->tower[i]);
    for (int i = 0; i != 49; i++)
        free(game->tower2[i]);
    free(game->tower);
    free(game->tower2);
}
