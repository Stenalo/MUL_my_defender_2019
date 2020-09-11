/*
** EPITECH PROJECT, 2020
** change
** File description:
** tutorial scene
*/

#include "defender.h"

void change_tutorial_menu_scenes(game_t *game, sfVector2i click_position)
{
    if (game->scene->game == false && game->scene->pause == false) {
        if (click_position.x > 70 && click_position.x < 350
        && click_position.y > 565 && click_position.y < 684) {
            sfMusic_play(game->music->button);
            game->scene->menu = false;
            game->scene->tutorial = true;
        }
    }
}
