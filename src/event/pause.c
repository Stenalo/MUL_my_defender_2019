/*
** EPITECH PROJECT, 2020
** make_pause
** File description:
** function
*/

#include "defender.h"

void draw_pause_scene(game_t *game)
{
    sfRenderWindow_drawSprite(game->core->window, game->map[1]->sprite, NULL);
    for (int j = 4; j != 7; j++) {
        sfRenderWindow_drawSprite(game->core->window,
        game->button[j]->sprite, NULL);
    }
}

void manage_pause(game_t *game)
{
    if (game->scene->pause == true) {
        sfMusic_play(game->music->button);
        game->scene->game = false;
        game->scene->pause = true;
        sfRenderWindow_clear(game->core->window, sfBlack);
    }
    if (game->scene->pause == true) {
        draw_pause_scene(game);
        update_menu_but_state(game);
    }
}
