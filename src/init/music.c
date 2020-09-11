/*
** EPITECH PROJECT, 2020
** music
** File description:
** file
*/

#include "defender.h"

music_t *init_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    music->button = sfMusic_createFromFile("sound/click.wav");
    music->game = sfMusic_createFromFile("sound/Tower-Defense_Looping.ogg");
    return (music);
}
