/*
** EPITECH PROJECT, 2020
** score
** File description:
** texts
*/

#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <time.h>
#include <stdlib.h>
#include "entity.h"
#include "scene.h"
#include "music.h"

typedef struct text_s {
    sfText *text;
    sfVector2f pos;
    sfFont *font;
    char *path;
    int score;
    sfClock *clock;
} text_t;
