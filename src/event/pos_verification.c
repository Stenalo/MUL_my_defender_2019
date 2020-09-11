/*
** EPITECH PROJECT, 2020
** inutile
** File description:
** mais obligatoire
*/

#include "my.h"
#include "defender.h"

bool pos_verification1(game_t *game)
{
    int i = 0;
    while (i != 40) {
        if ((game->cursor->pos.x + 40 >= game->tower[i]->position.x &&
            game->cursor->pos.x - 80 <= game->tower[i]->position.x + 40) &&
            (game->cursor->pos.y + 40 >= game->tower[i]->position.y &&
            game->cursor->pos.y - 80 <= game->tower[i]->position.y + 40))
            return (false);
        i++;
    }
    return (true);
}

bool pos_verification2(game_t *game)
{
    int i = 0;

    while (i != 40) {
        if ((game->cursor->pos.x + 40 >= game->tower2[i]->position.x &&
            game->cursor->pos.x - 80 <= game->tower2[i]->position.x + 40) &&
            (game->cursor->pos.y + 40 >= game->tower2[i]->position.y &&
            game->cursor->pos.y - 80 <= game->tower2[i]->position.y + 40))
            return (false);
        i++;
    }
    return (true);
}

bool pos_verif(game_t *game)
{
    if (game->cursor->pos.x >= 800 && game->cursor->pos.x <= 1100) {
        if (game->cursor->pos.y >= 400 && game->cursor->pos.y <= 700) {
            return (false);
        }
    }
    if (pos_verification2(game) == false)
        return (false);
    if (pos_verification1(game) == false)
        return (false);
    return (true);
}
