/*
** EPITECH PROJECT, 2020
** menu
** File description:
** button state
*/

#include "defender.h"

void initial_menu_rect(game_t *game)
{
    game->button[4]->rect.left = 0;
    game->button[5]->rect.left = 0;
    game->button[6]->rect.left = 0;
}

void update_menu_rect(game_t *game)
{
    sfSprite_setTextureRect(game->button[4]->sprite, game->button[4]->rect);
    sfSprite_setTextureRect(game->button[5]->sprite, game->button[5]->rect);
    sfSprite_setTextureRect(game->button[6]->sprite, game->button[6]->rect);
}

void update_menu_but_state(game_t *game)
{
    initial_menu_rect(game);
    if (game->scene->pause == true && game->scene->game == false) {
        if (game->cursor->pos.x > 871 && game->cursor->pos.x < 1100
            && game->cursor->pos.y > 310 && game->cursor->pos.y < 410)
            game->button[6]->rect.left = 37;
        if (game->cursor->pos.x > 871 && game->cursor->pos.x < 1100
            && game->cursor->pos.y > 610 && game->cursor->pos.y < 715)
            game->button[4]->rect.left = 29;
        if (game->cursor->pos.x > 871 && game->cursor->pos.x < 1048
            && game->cursor->pos.y > 460 && game->cursor->pos.y < 565)
            game->button[5]->rect.left = 29;
    }
    update_menu_rect(game);
}
