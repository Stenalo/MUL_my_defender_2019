/*
** EPITECH PROJECT, 2020
** change
** File description:
** scene
*/

#include "defender.h"

void manage_scene(game_t *game)
{
    sfRenderWindow_clear(game->core->window, sfBlack);
    manage_pause(game);
    if (game->scene->menu == true) {
        draw_menu(game);
    }
    if (game->scene->game == true) {
        game_event(game);
        draw_score(game);
        sfMusic_setLoop(game->music->game, sfTrue);
    }
    if (game->scene->tutorial == true)
        draw_tutorial(game);
    if (game->scene->end == true) {
        draw_best_score(game);
        update_end_but_state(game);
    }
}

void change_main_menu_scenes(game_t *game, sfVector2i click_position)
{
    if (game->scene->pause == false) {
        
        if (click_position.x > 70 && click_position.x < 252
        && click_position.y > 158 && click_position.y < 272) {
            sfMusic_play(game->music->button);
            game->scene->game = true;
            game->scene->menu = false;
            game->cursor->click = false;
        }
    }
    if (game->scene->game == false && game->scene->pause == false
    && game->scene-> == true) {
        if (click_position.x > 70 && click_position.x < 241
        && click_position.y > 760 && click_position.y < 860) {
            sfMusic_play(game->music->button);
            sfRenderWindow_close(game->core->window);
        }
    }
}

void change_pause_menu_scenes(game_t *game, sfVector2i click_position)
{
    if (game->scene->pause == true && game->scene->game == false) {
        if (click_position.x > 871 && click_position.x < 1100
        && click_position.y > 310 && click_position.y < 410) {
            sfMusic_play(game->music->button);
            game->scene->pause = false;
            game->scene->game = true;
        }
        if (click_position.x > 871 && click_position.x < 1048 \
        && click_position.y > 610 && click_position.y < 715) {
            sfMusic_play(game->music->button);
            sfRenderWindow_close(game->core->window);
        }
        if (click_position.x > 871 && click_position.x < 1048
        && click_position.y > 460 && click_position.y < 565) {
            sfMusic_play(game->music->button);
            game->scene->pause = false;
            game->scene->menu = true;
            reset_game(game);
        }
    }
}

int change_scenes(game_t *game, sfVector2i click_position)
{
    change_main_menu_scenes(game, click_position);
    change_pause_menu_scenes(game, click_position);
    change_tutorial_menu_scenes(game, click_position);
    change_end_menu_scenes(game, click_position);
    return (0);
}

void check_mouse_position(game_t *game, sfVector2i click_position)
{
    if (click_position.x > 70 && click_position.x < 250
    && click_position.y > 160 && click_position.y < 270) {
        sfMusic_play(game->music->button);
        game->button[0]->rect.left += 50;
        sfSprite_setTextureRect(game->button[0]->sprite, game->button[0]->rect);
    }
}
