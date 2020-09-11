/*
** EPITECH PROJECT, 2020
** tower
** File description:
** header
*/

#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <time.h>

typedef struct tower_s {
    sfTexture *texture;
    sfSprite *sprite;
    bool exist;
    sfVector2f position;
    sfIntRect rect;
    float life;
    bool attack;
    float damage;
    sfClock *clock;
    float seconds;
    sfMusic *mus;
    sfVector2f scale;
    sfTime time;
} tower_t;
