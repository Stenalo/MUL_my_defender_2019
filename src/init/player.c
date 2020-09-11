/*
** EPITECH PROJECT, 2020
** init
** File description:
** player
*/

#include "defender.h"

player_t *set_player(void)
{
    player_t *player = malloc(sizeof(player) * 1);
    player = malloc(sizeof(enemy_t));
    player->pos.x = 500;
    player->pos.y = 500;
    player->rect.top = 0;
    player->rect.left = 0;
    player->scale.x = 4;
    player->scale.y = 4;
    player->rect.width = 32;
    player->rect.height = 32;
    player->light = sflight_create();
    player->clock = sfClock_create();
    player->time = sfClock_getElapsedTime(player->clock);
    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile("image/player.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setScale(player->sprite, player->scale);
    return (player);
}
