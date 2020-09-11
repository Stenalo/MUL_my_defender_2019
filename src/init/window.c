/*
** EPITECH PROJECT, 2020
** init
** File description:
** window
*/

#include "defender.h"

core_t *set_window(void)
{
    core_t *core = malloc(sizeof(core_t));

    core->video_mode.width = 1920;
    core->video_mode.height = 1080;
    core->video_mode.bitsPerPixel = 32;
    core->window = sfRenderWindow_create(core->video_mode, "D",
    sfClose | sfResize, NULL);
    return (core);
}
