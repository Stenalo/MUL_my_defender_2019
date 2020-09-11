/*
** EPITECH PROJECT, 2020
** spawn
** File description:
** turret
*/

#include "../include/my.h"
#include "../include/defender.h"
#include <stdio.h>

void draw_turret(game_t *game, int i)
{
    while (i != 40) {
        if (game->tower[i]->exist == true) {
            sfSprite_setPosition(game->tower[i]->sprite,
            game->tower[i]->position);
            sfRenderWindow_drawSprite(game->core->window,
            game->tower[i]->sprite, NULL);
        }
        i++;
    }
}

void spawn_turret(game_t *game)
{
    int i = 0;

    if (game->cursor->click == true && pos_verif(game) == true
    && game->base->sel_tow == 1 && game->base->gold > 40) {
        game->base->gold -= 40;
        while (game->tower[i]->exist == true && i != 39)
            i++;
        game->base->gold -= 40;
        game->tower[i]->position.x = game->cursor->pos.x - 40;
        game->tower[i]->position.y = game->cursor->pos.y - 40;
        game->tower[i]->exist = true;
    }
    draw_turret(game, i);
}

void turret_attack2(game_t *game, tower_t *t, int i)
{
    int j = 0;

    while (j <= game->base->enemy_limit - 1) {
        if (check_tower_range(game->enemy[j], t) < 500 &&
        game->enemy[j]->life > 0) {
            game->particle[i]->exist = true;
            game->enemy[j]->life -= t->attack + 5;
            turret2_attack_anim(game->enemy[j], game, i);
            break;
        }
        j++;
    }
}
