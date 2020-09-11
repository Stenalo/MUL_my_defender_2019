/*
** EPITECH PROJECT, 2020
** anim
** File description:
** thunder
*/

#include "defender.h"

void thunder_anim(entity_t *t)
{
    t->time = sfClock_getElapsedTime(t->clock);
    t->seconds = sfTime_asSeconds(t->time);
    if (t->seconds >= 0.050 && t->seconds <= 0.1)t->rect.left = 1;
    if (t->seconds > 0.10 && t->seconds <= 0.15)t->rect.left = 43;
    if (t->seconds >= 0.15 && t->seconds <= 0.2)t->rect.left = 84;
    if (t->seconds > 0.2 && t->seconds <= 0.25)t->rect.left = 125;
    if (t->seconds > 0.25 && t->seconds <= 0.3)t->rect.left = 166;
    if (t->seconds > 0.3 && t->seconds <= 0.35)t->rect.left = 207;
    if (t->seconds > 0.35 && t->seconds <= 0.4)t->rect.left = 248;
    if (t->seconds > 0.40 && t->seconds <= 0.43)t->rect.width = 0;
    if (t->seconds > 0.42) {
        sfClock_restart(t->clock);
        t->rect.width = 39;
        t->seconds = 0;
        t->exist = false;
    }
    sfSprite_setTextureRect(t->sprite, t->rect);
}
