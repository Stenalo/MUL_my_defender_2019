/*
** EPITECH PROJECT, 2020
** enemy
** File description:
** header
*/

#include "my.h"
#include "defender.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <time.h>

typedef struct enemy_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    int life;
    bool attack;
    float damage;
    sfClock *clock;
    sfTime time;
    sfMusic *mus;
    sfIntRect rect;
    float seconds;
    float desconds;
    sfClock *dclock;
    sfTime dtime;
} enemy_t;
