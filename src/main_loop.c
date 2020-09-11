/*
** EPITECH PROJECT, 2020
** main
** File description:
** function
*/

#include "../include/my.h"
#include "../include/defender.h"

void check_window_close(game_t *game, sfEvent event)
{
    sfVector2i click_position;

    while (sfRenderWindow_pollEvent(game->core->window, &event)) {
        click_position = sfMouse_getPositionRenderWindow(game->core->window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->core->window);
        if (event.type == sfEvtMouseButtonPressed)
            change_scenes(game, click_position);
    }
}

void draw_tutorial(game_t *game)
{
    sfVector2f scale = {9.7, 9.7};
    sfVector2f pos = {30, 0};
    sfSprite *sprite_tit = sfSprite_create();
    sfTexture *texture_tit =
    sfTexture_createFromFile("image/TrueHowToPlay.png", NULL);

    sfSprite_setTexture(sprite_tit, texture_tit, sfFalse);
    sfSprite_setScale(sprite_tit, scale);
    sfSprite_setPosition(sprite_tit, pos);
    sfRenderWindow_drawSprite(game->core->window, sprite_tit, NULL);
}

void draw_menu(game_t *game)
{
    sfVector2f pos = {1920 / 2, 20};
    sfSprite *sprite_tit = sfSprite_create();
    sfTexture *texture_tit = sfTexture_createFromFile("image/title.png", NULL);

    sfSprite_setTexture(sprite_tit, texture_tit, sfFalse);
    sfSprite_setPosition(sprite_tit, pos);
    sfRenderWindow_drawSprite(game->core->window, game->map[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->core->window, sprite_tit, NULL);
    update_but_state(game);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(game->core->window,
        game->button[i]->sprite, NULL);
    }
}

int main_loop(void)
{
    game_t *game = init_game();
    sfEvent event;

    if (!game)
        return (-1);
    sfRenderWindow_setFramerateLimit(game->core->window, 60);
    while (sfRenderWindow_isOpen(game->core->window)) {
        check_window_close(game, event);
        game_input(game);
        manage_scene(game);
        game_display(game);
    }
    destroy_game(game);
    sfMusic_destroy(game->music->button);
    sfMusic_destroy(game->music->game);
    return (0);
}
