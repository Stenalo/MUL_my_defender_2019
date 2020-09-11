/*
** EPITECH PROJECT, 2020
** init
** File description:
** base
*/

#include "defender.h"

base_t *set_base(void)
{
    base_t *base = malloc(sizeof(base_t));

    base->sel_tow = 0;
    base->gold = 200;
    base->life = 10;
    base->exist = true;
    base->position.x = 900;
    base->position.y = 500;
    base->rect.top = 2;
    base->rect.left = 32;
    base->rect.width = 20;
    base->rect.height = 21;
    base->sprite = sfSprite_create();
    base->texture = sfTexture_createFromFile("image/turret.png", NULL);
    base->clock = sfClock_create();
    base->enemy_limit = 1;
    base->seconds = 0;
    base->enemy_hp = 5;
    sfSprite_setTexture(base->sprite, base->texture, sfTrue);
    sfSprite_setTextureRect(base->sprite, base->rect);
    return (base);
}
