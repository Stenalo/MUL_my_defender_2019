/*
** EPITECH PROJECT, 2020
** norme
** File description:
** norme
*/

#include "defender.h"

float check_tower_range(enemy_t *enemy, tower_t *tower)
{
    float p1 = powf(enemy->position.x - tower->position.x, 2);
    float p2 = powf(enemy->position.y - tower->position.y, 2);
    float dist = (fabs(sqrt(p1 + p2)));

    return (dist);
}

void turret2_attack_anim(enemy_t *e, game_t *g, int i)
{
    g->particle[i]->pos.y = e->position.y - 400;
    g->particle[i]->pos.x = e->position.x - 20;
    sfSprite_setPosition(g->particle[i]->sprite, g->particle[i]->pos);
}

void anim_turret22(tower_t *t)
{
    if (t->seconds > 1.0 && t->seconds <= 1.1)t->rect.left = 161;
    if (t->seconds > 1.1 && t->seconds <= 1.2)t->rect.left = 177;
    if (t->seconds > 1.2 && t->seconds <= 1.3)t->rect.left = 193;
    if (t->seconds > 1.3 && t->seconds <= 1.4)t->rect.left = 209;
    if (t->seconds > 1.4 && t->seconds <= 1.5)t->rect.left = 225;
    if (t->seconds > 1.5 && t->seconds <= 1.6)t->rect.left = 241;
    if (t->seconds > 1.6 && t->seconds <= 1.7)t->rect.left = 257;
    if (t->seconds > 1.7) {
        sfClock_restart(t->clock);
        t->seconds = 0;
    }
}
