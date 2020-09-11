/*
** EPITECH PROJECT, 2020
** init
** File description:
** tower
*/

#include "defender.h"

void set_tower_texture(tower_t **tower, int i)
{
    sfSprite_setScale(tower[i]->sprite, tower[i]->scale);
    sfSprite_setTexture(tower[i]->sprite, tower[i]->texture, sfTrue);
    sfSprite_setTextureRect(tower[i]->sprite, tower[i]->rect);
}

entity_t **set_particle(void)
{
    entity_t **particle = malloc(sizeof(entity_t *) * 41);

    for (int i = 0; i != 40; i++) {
        particle[i] = malloc(sizeof(entity_t));
        particle[i]->pos.x = -500;
        particle[i]->pos.y = -500;
        particle[i]->rect = rect();
        particle[i]->scale.x = 4;
        particle[i]->scale.y = 4;
        particle[i]->exist = false;
        particle[i]->clock = sfClock_create();
        particle[i]->time = sfClock_getElapsedTime(particle[i]->clock);
        particle[i]->sprite = sfSprite_create();
        particle[i]->texture = sfTexture_createFromFile("image/l.png", NULL);
        sfSprite_setTexture(particle[i]->sprite, particle[i]->texture, sfTrue);
        sfSprite_setScale(particle[i]->sprite, particle[i]->scale);
    }
    return (particle);
}

tower_t **set_tower2(void)
{
    tower_t **tower = malloc(sizeof(tower_t *) * 50);

    for (int i = 0; i != 49; i++) {
        tower[i] = malloc(sizeof(tower_t));
        tower[i]->life = 0;
        tower[i]->exist = false;
        tower[i]->position.x = -500;
        tower[i]->position.y = -500;
        tower[i]->rect = set_tower2_rect();
        tower[i]->scale.x = 4;
        tower[i]->scale.y = 4;
        tower[i]->attack = 1;
        tower[i]->clock = sfClock_create();
        tower[i]->time = sfClock_getElapsedTime(tower[i]->clock);
        tower[i]->sprite = sfSprite_create();
        tower[i]->texture = sfTexture_createFromFile("image/turret2.png", NULL);
        set_tower_texture(tower, i);
    }
    return (tower);
}

tower_t **set_tower(void)
{
    tower_t **tower = malloc(sizeof(tower_t *) * 50);

    for (int i = 0; i != 49; i++) {
        tower[i] = malloc(sizeof(tower_t));
        tower[i]->life = 0;
        tower[i]->exist = false;
        tower[i]->position.x = -500;
        tower[i]->position.y = -500;
        tower[i]->rect = set_tower_rect();
        tower[i]->scale.x = 4;
        tower[i]->scale.y = 4;
        tower[i]->attack = 1;
        tower[i]->clock = sfClock_create();
        tower[i]->time = sfClock_getElapsedTime(tower[i]->clock);
        tower[i]->sprite = sfSprite_create();
        tower[i]->texture = sfTexture_createFromFile("image/turr2.png", NULL);
        set_tower_texture(tower, i);
    }
    return (tower);
}
