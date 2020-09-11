/*
** EPITECH PROJECT, 2020
** anim
** File description:
** enemies
*/

#include "defender.h"

void enemy_anim(enemy_t *enemy)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = sfTime_asSeconds(enemy->time);
    if (enemy->seconds >= 0.0 && enemy->seconds <= 0.1) {
        enemy->rect.left = 2;
    }
    if (enemy->seconds > 0.1 && enemy->seconds <= 0.2) {
        enemy->rect.left = 50;
    }
    if (enemy->seconds > 0.2 && enemy->seconds <= 0.3) {
        enemy->rect.left = 98;
    }
    if (enemy->seconds > 0.3) {
        sfClock_restart(enemy->clock);
        enemy->seconds = 0;
    }
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
}

void enemy_move(enemy_t *enemy, game_t *game)
{
    enemy->position.x += (960 - enemy->position.x) / 200;
    enemy->position.y += (590 - enemy->position.y) / 200;
    if (enemy->position.x >= 800 && enemy->position.x <= 1100) {
        if (enemy->position.y >= 400 && enemy->position.y <= 700) {
            enemy->life = false;
            game->base->life--;
        }
    }
}
