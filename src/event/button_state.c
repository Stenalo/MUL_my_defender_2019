/*
** EPITECH PROJECT, 2020
** button
** File description:
** state
*/

#include "defender.h"

void initial_rect(game_t *game)
{
    if (game->cursor->pos.x < 70 || game->cursor->pos.x > 252 ||
    game->cursor->pos.y < 158 || game->cursor->pos.y > 272) {
        game->button[0]->rect.top = 0;
        game->button[0]->rect.left = 0;
    }
    game->button[3]->rect.left = 0;
    game->button[1]->rect.left = 0;
    game->button[2]->rect.left = 0;
}

void update_button_rect(game_t *game)
{
    sfSprite_setTextureRect(game->button[0]->sprite, game->button[0]->rect);
    sfSprite_setTextureRect(game->button[3]->sprite, game->button[3]->rect);
    sfSprite_setTextureRect(game->button[1]->sprite, game->button[1]->rect);
    sfSprite_setTextureRect(game->button[2]->sprite, game->button[2]->rect);
}

void button_anim(game_t *game)
{
    game->button[0]->time = sfClock_getElapsedTime(game->button[0]->clock);
    game->button[0]->seconds = sfTime_asSeconds(game->button[0]->time);
    if (game->button[0]->seconds >= 0.0 && game->button[0]->seconds < 0.1) {
        game->button[0]->rect.left = 0;
        game->button[0]->rect.top = 36;
    }
    if (game->button[0]->seconds >= 0.1 && game->button[0]->seconds < 0.2)
        game->button[0]->rect.left = 29;
    if (game->button[0]->seconds >= 0.2 && game->button[0]->seconds < 0.3)
        game->button[0]->rect.left = 58;
    if (game->button[0]->seconds >= 0.3 && game->button[0]->seconds < 0.4) {
        game->button[0]->rect.left = 0;
        game->button[0]->rect.top = 54;
    }
    if (game->button[0]->seconds >= 0.4 && game->button[0]->seconds < 0.5)
        game->button[0]->rect.left = 29;
    if (game->button[0]->seconds >= 0.5 && game->button[0]->seconds < 0.6)
        game->button[0]->rect.left = 58;
    if (game->button[0]->seconds >= 0.6) {
        sfClock_restart(game->button[0]->clock);
        game->button[0]->seconds = 0;
    }
}

void initial_rect_play(game_t *game)
{
    game->button[0]->rect.top = 0;
    game->button[0]->rect.left = 0;
}

void update_but_state(game_t *game)
{
    initial_rect(game);
    if (game->scene->menu == true && game->scene->game == false) {
        if (game->cursor->pos.x >= 70 && game->cursor->pos.x <= 252 &&
            game->cursor->pos.y >= 158 && game->cursor->pos.y <= 272)
            button_anim(game);
        if (game->cursor->pos.x >= 70 && game->cursor->pos.x <= 241
            && game->cursor->pos.y >= 760 && game->cursor->pos.y <= 860)
            game->button[3]->rect.left = 29;
        if (game->cursor->pos.x >= 70 && game->cursor->pos.x <= 307
            && game->cursor->pos.y >= 360 && game->cursor->pos.y <= 460)
            game->button[1]->rect.left = 37;
        if (game->cursor->pos.x >= 70 && game->cursor->pos.x <= 350
            && game->cursor->pos.y >= 565 && game->cursor->pos.y <= 684)
            game->button[2]->rect.left = 43;
        update_button_rect(game);
    }
}
