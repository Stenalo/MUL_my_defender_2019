/*
** EPITECH PROJECT, 2020
** input
** File description:
** game
*/

#include "../include/my.h"
#include "../include/defender.h"

void select_tower(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1) == sfTrue)
        game->base->sel_tow = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum2) == sfTrue)
        game->base->sel_tow = 2;
    if (sfKeyboard_isKeyPressed(sfKeyNum3) == sfTrue)
        game->base->sel_tow = 3;
}

void other_input(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue &&\
        game->scene->menu == false)
        game->scene->pause = true;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue &&\
    game->scene->tutorial == true) {
        game->scene->tutorial = false;
        game->scene->pause = false;
        game->scene->menu = true;
    }
}

int game_input(game_t *game)
{
    select_tower(game);
    game->cursor->pos.x = sfMouse_getPositionRenderWindow(game->core->window).x;
    game->cursor->pos.y = sfMouse_getPositionRenderWindow(game->core->window).y;
    other_input(game);
    if (game->cursor->hold == true &&                   \
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        game->cursor->click = false;
        return (0);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        game->cursor->click = true;
        game->cursor->hold = true;
        return (0);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse) {
        game->cursor->click = false;
        game->cursor->hold = false;
        return (0);
    }
    return (-1);
}
