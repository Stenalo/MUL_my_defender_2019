/*
** EPITECH PROJECT, 2020
** reset
** File description:
** game file
*/

#include "defender.h"

void reset_enemy(game_t *game)
{
    for (int i = 0; i != ENEMY_MAX; i++) {
        game->enemy[i]->life = 0;
        game->enemy[i]->position.x = -50;
        game->enemy[i]->position.y = -50;
    }
    game->base->enemy_limit = 1;
    game->base->enemy_hp = 5;
}

void reset_tower(game_t *game)
{
    for (int i = 0; i != 49; i++) {
        game->tower[i]->life = 0;
        game->tower[i]->exist = false;
        game->tower[i]->position.x = -500;
        game->tower[i]->position.y = -500;
        game->tower2[i]->life = 0;
        game->tower2[i]->exist = false;
        game->tower2[i]->position.x = -500;
        game->tower2[i]->position.y = -500;
    }
}

void reset_particle(game_t *game)
{
    for (int i = 0; i != 40; i++) {
        game->particle[i]->pos.x = -500;
        game->particle[i]->pos.y = -500;
    }
}

void reset_base(game_t *game)
{
    game->base->sel_tow = 0;
    game->base->gold = 200;
    game->base->life = 10;
    game->base->exist = true;
}

void reset_game(game_t *game)
{
    reset_base(game);
    reset_enemy(game);
    reset_tower(game);
    reset_particle(game);
    game->hud[1]->score = 0;
}