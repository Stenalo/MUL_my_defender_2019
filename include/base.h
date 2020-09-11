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

typedef struct base_s {
    sfTexture *texture;
    int sel_tow;
    sfSprite *sprite;
    int life;
    int enemy_limit;
    int gold;
    bool exist;
    sfVector2f position;
    sfIntRect rect;
    int enemy_hp;
    sfClock *clock;
    sfTime time;
    float seconds;
} base_t;
