/*
** EPITECH PROJECT, 2020
** spawn
** File description:
** turret
*/

#include "../include/my.h"
#include "../include/defender.h"
#include <stdio.h>

void anim_turret2(tower_t *t)
{
    t->time = sfClock_getElapsedTime(t->clock);
    t->seconds = sfTime_asSeconds(t->time);
    if (t->seconds >= 0.0 && t->seconds <= 0.1)t->rect.left = 1;
    if (t->seconds > 0.1 && t->seconds <= 0.2)t->rect.left = 17;
    if (t->seconds > 0.2 && t->seconds <= 0.3)t->rect.left = 33;
    if (t->seconds > 0.3 && t->seconds <= 0.4)t->rect.left = 49;
    if (t->seconds > 0.4 && t->seconds <= 0.5)t->rect.left = 65;
    if (t->seconds > 0.5 && t->seconds <= 0.6)t->rect.left = 81;
    if (t->seconds > 0.6 && t->seconds <= 0.7)t->rect.left = 97;
    if (t->seconds > 0.7 && t->seconds <= 0.8)t->rect.left = 113;
    if (t->seconds > 0.8 && t->seconds <= 0.9)t->rect.left = 129;
    if (t->seconds > 0.9 && t->seconds <= 1.0)t->rect.left = 145;
    if (t->seconds > 1.0)
        anim_turret22(t);
    sfSprite_setTextureRect(t->sprite, t->rect);
}

void norm_draw_turret2(game_t *game, int i)
{
    if (game->particle[i]->exist == false)
        turret_attack2(game, game->tower2[i], i);
}

void draw_turret2(game_t *game)
{
    int i = 0;
    while (i != 39) {
        if (game->tower2[i]->exist == true) {
            anim_turret2(game->tower2[i]);
            sfRenderWindow_drawSprite(game->core->window,
            game->tower2[i]->sprite, NULL);
            norm_draw_turret2(game, i);
        }
        i++;
    }
}

void norme_spawn_turret2(game_t *game, int j)
{
    if (game->particle[j]->exist == true) {
        thunder_anim(game->particle[j]);
        sfRenderWindow_drawSprite(game->core->window,
        game->particle[j]->sprite, NULL);
    } else {
        sfClock_restart(game->particle[j]->clock);
        game->particle[j]->seconds = 0;
    }
}

void spawn_turret2(game_t *game)
{
    int i = 0;
    if (game->cursor->click == true && pos_verif(game) == true &&
    game->base->sel_tow == 2 && game->base->gold >= 20) {
        game->base->gold -= 20;
        for (i = 0; game->tower2[i]->exist == true && i != 39; i++);
        game->tower2[i]->position.x = game->cursor->pos.x - 40;
        game->tower2[i]->position.y = game->cursor->pos.y - 40;
        sfSprite_setPosition(TOWER2[i]->sprite, game->tower2[i]->position);
        game->tower2[i]->exist = true;
    }
    draw_turret2(game);
    for (int j = 0; j != 39; j++) {
        norme_spawn_turret2(game, j);
    }
}
