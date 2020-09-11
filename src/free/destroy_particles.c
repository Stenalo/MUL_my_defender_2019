/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** particles
*/

#include "defender.h"

void destroy_particles(game_t *game)
{
    for (int i = 0; i != 40; i++)
        free(game->particle[i]);
    free(game->particle);
}
