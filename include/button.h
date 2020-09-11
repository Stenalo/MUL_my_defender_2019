/*
** EPITECH PROJECT, 2020
** button
** File description:
** header
*/

#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <time.h>

typedef struct button_s {
    sfVector2f pos;
    sfRectangleShape *rectangle;
    sfClock *clock;
    float seconds;
    sfTime time;
} button_t;

#endif
