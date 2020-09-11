/*
** EPITECH PROJECT, 2020
** init
** File description:
** enemies
*/

#include "defender.h"

enemy_t **set_enemy(void)
{
    enemy_t **enemy = malloc(sizeof(enemy_t *) * ENEMY_MAX);

    for (int i = 0; i != ENEMY_MAX; i++) {
        enemy[i] = malloc(sizeof(enemy_t));
        enemy[i]->life = 0;
        enemy[i]->position.x = -50;
        enemy[i]->position.y = -50;
        enemy[i]->rect.top = 2;
        enemy[i]->rect.left = 2;
        enemy[i]->rect.width = 45;
        enemy[i]->rect.height = 64;
        enemy[i]->clock = sfClock_create();
        enemy[i]->time = sfClock_getElapsedTime(enemy[i]->clock);
        enemy[i]->sprite = sfSprite_create();
        enemy[i]->texture = sfTexture_createFromFile("image/TESS.png", NULL);
        enemy[i]->dclock = sfClock_create();
        enemy[i]->desconds = 0;
        sfSprite_setTexture(enemy[i]->sprite, enemy[i]->texture, sfTrue);
        sfSprite_setTextureRect(enemy[i]->sprite, enemy[i]->rect);
    }
    return (enemy);
}
