/*
** EPITECH PROJECT, 2019
** defender
** File description:
** music
*/

#ifndef __MUSIC_H__
#define __MUSIC_H__
#include <SFML/Audio.h>

typedef struct music_s {
    sfMusic *game;
    sfMusic *menu;
    sfMusic *button;
} music_t;

#endif
