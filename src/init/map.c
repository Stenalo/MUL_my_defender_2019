/*
** EPITECH PROJECT, 2020
** init
** File description:
** backgrounsd images
*/

#include "defender.h"

void set_map_texture(entity_t **map)
{
    map[0]->texture = sfTexture_createFromFile("image/bg.png", NULL);
    map[1]->texture = sfTexture_createFromFile("image/PauseMenu1.png", NULL);
    sfSprite_setTexture(map[0]->sprite, map[0]->texture, sfTrue);
    sfSprite_setTexture(map[1]->sprite, map[1]->texture, sfTrue);
}

entity_t **set_map(void)
{
    entity_t **map = malloc(sizeof(entity_t *) * 2);

    for (int i = 0; i != 2; i++) {
        map[i] = malloc(sizeof(entity_t));
        map[i]->pos.x = 0;
        map[i]->pos.y = 0;
        map[i]->sprite = sfSprite_create();
        map[i]->scale.x = 1.5;
        map[i]->scale.y = 1.5;
    }
    set_map_texture(map);
    return (map);
}