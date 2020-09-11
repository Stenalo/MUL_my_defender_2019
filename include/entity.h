/*
** EPITECH PROJECT, 2019
** entity
** File description:
**  header
*/

#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "defender.h"
#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <time.h>
#include <stdlib.h>

typedef struct entity_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *rectan;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    bool exist;
    float seconds;
    sfTime time;
    char *path;
} entity_t;

#endif
