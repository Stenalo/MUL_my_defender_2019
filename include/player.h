/*
** EPITECH PROJECT, 2019
** entity
** File description:
**  header
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "defender.h"
#include "../toCopyLIGHT/include/light.h"
#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <time.h>
#include <stdlib.h>

typedef struct player_s {
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
    sfLight *light;
} player_t;

#endif
