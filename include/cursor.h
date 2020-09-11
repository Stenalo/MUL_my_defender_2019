/*
** EPITECH PROJECT, 2020
** cursor
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

typedef struct cursor_s {
    bool click;
    bool hold;
    sfVector2f pos;
} cursor_t;
