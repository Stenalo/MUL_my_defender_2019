/*
** EPITECH PROJECT, 2020
** t
** File description:
** t
*/

#include "my.h"
#include "defender.h"
#include <math.h>
#include <stdio.h>

void firing_turret(tower_t *t)
{
    t->time = sfClock_getElapsedTime(t->clock);
    t->seconds = sfTime_asSeconds(t->time);
    if (t->seconds >= 0.05 && t->seconds <= 0.1) {
        t->rect.top = 41;
    }
    if (t->seconds > 0.15 && t->seconds <= 0.2) {
        t->rect.top = 81;
    }
    if (t->seconds > 0.2) {
        sfClock_restart(t->clock);
        t->seconds = 0;
    }

}

bool cross_anim_turert(enemy_t *e, tower_t *t)
{
    if (e->position.x > t->position.x - 80 &&
    e->position.x < t->position.x + 80) {
        if (e->position.y > t->position.y) {
            t->rect.left = 91;
        } else {
            t->rect.left = 61;
        }
        return (true);
    }
    if (e->position.y > t->position.y - 80 &&
    e->position.y < t->position.y + 80) {
        if (e->position.x > t->position.x) {
            t->rect.left = 1;
        } else {
            t->rect.left = 31;
        }
        return (true);
    }
    return (false);
}

void anim_turret(enemy_t *e, tower_t *t)
{
    if (cross_anim_turert(e, t) == false) {
        if (t->position.x > e->position.x && t->position.y > e->position.y)
            t->rect.left = 121;
        if (t->position.x <= e->position.x && t->position.y > e->position.y)
            t->rect.left = 211;
        if (t->position.x <= e->position.x && t->position.y <= e->position.y)
            t->rect.left = 181;
        if (t->position.x > e->position.x && t->position.y <= e->position.y)
            t->rect.left = 151;
    }

    firing_turret(t);
    sfSprite_setTextureRect(t->sprite, t->rect);
}

void norme_turret_attack(game_t *game, int i)
{
    int j = 0;
    while (j <= game->base->enemy_limit - 1) {
        game->tower[i]->rect.top = 1;
        if (check_tower_range(game->enemy[j], game->tower[i]) < 300) {
            game->enemy[j]->life -= game->tower[i]->attack;
            anim_turret(game->enemy[j], game->tower[i]);
            break;
        }
        j++;
    }
}

void turret_attack(game_t *game)
{
    int i = 0;

    while (i <= 40) {
        norme_turret_attack(game, i);
        i++;
    }
    return;
}

