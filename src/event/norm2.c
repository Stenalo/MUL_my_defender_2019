/*
** EPITECH PROJECT, 2020
** norme
** File description:
** norme
*/

#include "defender.h"

void base_life(game_t *game)
{
    if (game->base->life < 0) {
        game->scene->game = false;
        game->scene->end = true;
    }
}

void draw_hud(game_t *game)
{
    if (game->base->sel_tow == 1)
        game->hud[0]->tower_rect.left = 105;
    if (game->base->sel_tow == 2)
        game->hud[0]->tower_rect.left = 209;
    if (game->base->sel_tow == 3)
        game->hud[0]->tower_rect.left = 313;
    sfSprite_setTextureRect(game->hud[0]->tower_spr, game->hud[0]->tower_rect);
    sfRenderWindow_drawSprite(game->core->window,
    game->hud[0]->tower_spr, NULL);
}

bool ivl(float number, float interval)
{
    if (number > interval - 0.01 && number < interval + 0.01)
        return (true);
    return (false);
}

void game_difficulty(game_t *game)
{
    game->base->time = sfClock_getElapsedTime(game->base->clock);
    game->base->seconds = sfTime_asSeconds(game->base->time);
    if (ivl(game->base->seconds, 4.0) == true &&
        game->base->enemy_limit + 1 < 50)
        game->base->enemy_limit += 2;
    if (ivl(game->base->seconds, 7.0)) {
        game->base->enemy_hp += 10;
        sfClock_restart(game->base->clock);
        game->base->seconds = 0;
    }
}

void player_anim(game_t *game)
{
    game->player->time = sfClock_getElapsedTime(game->player->clock);
    game->player->seconds = sfTime_asSeconds(game->player->time);
    if (game->player->seconds >= 0.0 && game->player->seconds <= 0.2)
        game->player->rect.left = 0;
    if (game->player->seconds > 0.2 && game->player->seconds <= 0.3)
        game->player->rect.left = 32;
    if (game->player->seconds > 0.3 && game->player->seconds <= 0.5)
        game->player->rect.left = 64;
    if (game->player->seconds >= 0.5 && game->player->seconds <= 0.6)
        game->player->rect.left = 96;
    if (game->player->seconds > 0.6 && game->player->seconds <= 0.8)
        game->player->rect.left = 128;
    if (game->player->seconds > 0.8 && game->player->seconds <= 1)
        game->player->rect.left = 160;
    if (game->player->seconds > 1.2) {
        sfClock_restart(game->player->clock);
        game->player->seconds = 0;
    }
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}
