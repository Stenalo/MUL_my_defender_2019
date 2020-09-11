/*
** EPITECH PROJECT, 2020
** end
** File description:
** scene
*/

#include "defender.h"
#include "defender.h"

void change_end_menu_scenes(game_t *game, sfVector2i click_position)
{
    if (game->scene->game == false && game->scene->end == true) {
        if (click_position.x > 611 && click_position.x < 788
        && click_position.y > 912 && click_position.y < 1011) {
            game->scene->end = false;
            game->scene->game = true;
            reset_game(game);
            game->hud[1]->pos.x = 1835;
            game->hud[1]->pos.y = 50;
            sfText_setCharacterSize(game->hud[1]->text, 20);
            sfText_setPosition(game->hud[1]->text, game->hud[1]->pos);
        }
        if (click_position.x > 908 && click_position.x < 1087
            && click_position.y > 912 && click_position.y < 1011)
            sfRenderWindow_close(game->core->window);
    }
}
