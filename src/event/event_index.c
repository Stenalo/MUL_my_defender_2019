/*
** EPITECH PROJECT, 2020
** index
** File description:
** event
*/

#include "../include/my.h"
#include "../include/defender.h"

void player_interaction(game_t *game)
{
    int i = 0;

    while (i != game->base->enemy_limit) {
        if (check_player_range(game->enemy[i], game->player) < 200) {
            game->enemy[i]->position.x -=
            (960 - game->enemy[i]->position.x) / 180;
            game->enemy[i]->position.y -=
            (590 - game->enemy[i]->position.y) / 180;
        }
        i++;
    }
}

void player_light(game_t *game)
{
    sflight_setradius(game->player->light, 170);
    player_halo_anim(game);
    sflight_setcolorfromrgb(game->player->light, 3, 30, 230);
    sflight_settransparency(game->player->light, 25);
    sflight_setposition(game->player->light, game->player->pos.x +\
    (game->player->rect.width / 2 * game->player->scale.x), game->player->pos.y\
    + (game->player->rect.height / 2 * game->player->scale.x));
    sflight_setcolorfromrgb(game->player->light, 255, 250, 163);
    sflight_setmode(game->player->light, LIGHT_LAYR);
    sflight_setgradientlayer(game->player->light, 5);
    sflight_display(game->player->light, game->core->window);
}

void draw_player(game_t *game)
{
    player_anim(game);
    player_move(game);
    player_light(game);
    player_interaction(game);
    sfRenderWindow_drawSprite(game->core->window, game->player->sprite, NULL);
}

void game_event(game_t *game)
{
    game_difficulty(game);
    base_life(game);
    sfRenderWindow_drawSprite(game->core->window, game->map[0]->sprite, NULL);
    spawn_enemy(game);
    spawn_turret(game);
    spawn_turret2(game);
    spawn_turret3(game);
    turret_attack(game);
    draw_player(game);
    draw_hud(game);
    sfMusic_play(game->music->game);
    sfMusic_setLoop(game->music->game, sfTrue);
}
