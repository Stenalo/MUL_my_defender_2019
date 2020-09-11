/*
** EPITECH PROJECT, 2020
** init
** File description:
** scene
*/

#include "defender.h"

scene_t *set_scene(void)
{
    scene_t *scene;

    scene = malloc(sizeof(scene_t));
    scene->menu = true;
    scene->game = false;
    scene->end = false;
    scene->pause = false;
    scene->tutorial = false;
    return (scene);
}