/*
** EPITECH PROJECT, 2020
** end
** File description:
** button state
*/

#include "defender.h"

void initial_end_rect(game_t *game)
{
    game->button[7]->rect.top = 0;
    game->button[8]->rect.left = 0;
}

void update_end_rect(game_t *game)
{
    sfSprite_setTextureRect(game->button[7]->sprite, game->button[7]->rect);
    sfSprite_setTextureRect(game->button[8]->sprite, game->button[8]->rect);
}

void update_end_but_state(game_t *game)
{
    initial_end_rect(game);
    if (game->scene->end == true && game->scene->game == false) {
        if (game->cursor->pos.x > 908 && game->cursor->pos.x < 1087
        && game->cursor->pos.y > 912 && game->cursor->pos.x < 1011) {
            sfMusic_play(game->music->button);
            game->button[8]->rect.left = 29;
        }
        if (game->cursor->pos.x > 611 && game->cursor->pos.x < 788
            && game->cursor->pos.y > 912 && game->cursor->pos.x < 1011)
            game->button[7]->rect.top = 35;
    }
    update_end_rect(game);
}
