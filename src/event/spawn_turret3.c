/*
** EPITECH PROJECT, 2020
** spawn
** File description:
** turret
*/

#include "../include/my.h"
#include "../include/defender.h"
#include <stdio.h>
void anim_turret3(tower_t *t, game_t *game)
{
    t->time = sfClock_getElapsedTime(t->clock);
    t->seconds = sfTime_asSeconds(t->time);
    if (t->seconds >= 0.0 && t->seconds <= 0.3)t->rect.left = 0;
    if (t->seconds > 0.3 && t->seconds <= 0.6)t->rect.left = 32;
    if (t->seconds > 0.6 && t->seconds <= 0.9)t->rect.left = 64;
    if (t->seconds > 0.9 && t->seconds <= 1.2)t->rect.left = 96;
    if (t->seconds > 1.2 && t->seconds <= 1.5)t->rect.left = 128;
    if (t->seconds > 1.5) {
        game->base->gold += 10;
        sfClock_restart(t->clock);
        t->seconds = 0;
    }
    sfSprite_setTextureRect(t->sprite, t->rect);
}

void draw_turret3(game_t *game)
{
    int i = 0;
    while (i != 39) {
        if (game->tower3[i]->exist == true) {
            anim_turret3(game->tower3[i], game);
            sfRenderWindow_drawSprite(game->core->window,   \
            game->tower3[i]->sprite, NULL);
        }
        i++;
    }
}

void spawn_turret3(game_t *game)
{
    int i = 0;

    if (game->cursor->click == true && pos_verif(game) == true &&
    game->base->sel_tow == 3 && game->base->gold >= 100) {
        game->base->gold -= 100;
        for (i = 0; game->tower3[i]->exist == true && i != 39; i++);
        game->tower3[i]->position.x = game->cursor->pos.x - 40;
        game->tower3[i]->position.y = game->cursor->pos.y - 40;
        sfSprite_setPosition(game->tower3[i]->sprite,
        game->tower3[i]->position);
        game->tower3[i]->exist = true;
    }
    draw_turret3(game);
}
