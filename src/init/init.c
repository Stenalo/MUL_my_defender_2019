/*
** EPITECH PROJECT, 2020
** init
** File description:
** all
*/

#include "defender.h"
#include "my.h"

tower_t **set_tower3(void)
{
    tower_t **tower = malloc(sizeof(tower_t *) * 50);

    for (int i = 0; i != 49; i++) {
        tower[i] = malloc(sizeof(tower_t));
        tower[i]->life = 0;
        tower[i]->exist = false;
        tower[i]->position.x = -500;
        tower[i]->position.y = -500;
        tower[i]->rect = rect3();
        tower[i]->scale.x = 4;
        tower[i]->scale.y = 4;
        tower[i]->attack = 1;
        tower[i]->clock = sfClock_create();
        tower[i]->time = sfClock_getElapsedTime(tower[i]->clock);
        tower[i]->sprite = sfSprite_create();
        tower[i]->texture = sfTexture_createFromFile("image/gold_t.png", NULL);
        set_tower_texture(tower, i);
    }
    return (tower);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->tower3 = set_tower3();
    game->core = set_window();
    game->enemy = set_enemy();
    game->tower = set_tower();
    game->base = set_base();
    game->cursor = set_cursor();
    game->scene = set_scene();
    game->button = set_button();
    game->map = set_map();
    game->music = init_music();
    game->hud = set_hud();
    game->particle = set_particle();
    game->tower2 = set_tower2();
    game->player = set_player();
    return (game);
}
