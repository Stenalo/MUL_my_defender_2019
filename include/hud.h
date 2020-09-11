/*
** EPITECH PROJECT, 2020
** hud
** File description:
** header
*/

#ifndef _HUD_H_
#define _HUD_H_
#include "defender.h"
#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <time.h>
#include <stdlib.h>

typedef struct hud_s {
    sfText *text;
    sfFont *font;
    sfClock *test;
    sfTexture *tex;
    sfClock *clock;
    sfSprite *sprite;
    sfSprite *tower_spr;
    sfTexture *tower_tex;
    sfVector2f tower_pos;
    sfVector2f tower_sca;
    sfVector2f pos;
    sfIntRect tower_rect;
    int life;
    int score;
    int coin;
} hud_t;
#endif