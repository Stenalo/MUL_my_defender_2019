/*
** EPITECH PROJECT, 2020
** norme
** File description:
** norme
*/

#include "defender.h"

void player_halo_anim(game_t *game)
{
    if (game->player->seconds <= 0.6) {
        game->player->light->radius = 170 - game->player->seconds * 50;
    } else {
        game->player->light->radius = 110 + game->player->seconds * 50;
    }
    sflight_setradius(game->player->light, game->player->light->radius);
}

void player_move(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        game->player->pos.y -= 3;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        game->player->pos.y += 3;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        game->player->pos.x += 3;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        game->player->pos.x -= 3;
    sfSprite_setPosition(game->player->sprite, game->player->pos);
}

float check_player_range(enemy_t *enemy, player_t *player)
{
    float p1 = powf(enemy->position.x - player->pos.x, 2);
    float p2 = powf(enemy->position.y - player->pos.y, 2);
    float dist = (fabs(sqrt(p1 + p2)));

    return (dist);
}
