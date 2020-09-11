/*
** EPITECH PROJECT, 2020
** spawn
** File description:
** enemy
*/

#include "../include/my.h"
#include "../include/defender.h"

void rand_ene_pos(enemy_t *enemy, game_t *game)
{
    int r = rand() % 5;

    enemy->life = game->base->enemy_hp;
    if (r == 0) {
        enemy->position.x = (rand() % 1920);
        enemy->position.y = -80;
    }
    if (r == 2) {
        enemy->position.x = (rand() % 1920);
        enemy->position.y = 1080;
    }if (r == 3) {
        enemy->position.x = -80;
        enemy->position.y = (rand() % 1080);
    }
    if (r == 4) {
        enemy->position.x = 1920;
        enemy->position.y = (rand() % 1080);
    }
}

void set_enemy_rect(enemy_t *enemy)
{
    if (enemy->position.x > 960 && enemy->position.y <= 540)
        enemy->rect.top = 2;
    if (enemy->position.x <= 960 && enemy->position.y <= 540)
        enemy->rect.top = 68;
    if (enemy->position.x > 960 && enemy->position.y > 540)
        enemy->rect.top = 134;
    if (enemy->position.x <= 960 && enemy->position.y > 540)
        enemy->rect.top = 200;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
}

void dead_enemy(enemy_t *enemy, game_t *game)
{
    enemy->dtime = sfClock_getElapsedTime(enemy->dclock);
    enemy->desconds = sfTime_asSeconds(enemy->dtime);
    if (enemy->desconds >= 0.0 && enemy->desconds <= 0.1) {
        enemy->rect.left = 145;
    }
    if (enemy->desconds > 0.1 && enemy->desconds <= 0.2) {
        enemy->rect.left = 193;
    }
    if (enemy->desconds > 0.2 && enemy->desconds <= 0.3) {
        enemy->rect.left = 241;
    }
    if (enemy->desconds > 0.3) {
        rand_ene_pos(enemy, game);
        set_enemy_rect(enemy);
        game->base->gold += 5;
    }
}

void set_enemy_pos(enemy_t *enemy, game_t *game)
{
    if (enemy->life == 0) {
        dead_enemy(enemy, game);
    }
    else {
        enemy_anim(enemy);
        enemy_move(enemy, game);
    }
    sfSprite_setPosition(enemy->sprite, enemy->position);
}

void spawn_enemy(game_t *game)
{
    int i = 0;
    while (i != game->base->enemy_limit - 1) {
        if (game->enemy[i]->life <= 0)
            game->enemy[i]->life = 0;
        set_enemy_pos(game->enemy[i], game);
        sfRenderWindow_drawSprite(game->core->window, \
        game->enemy[i]->sprite, NULL);
        i++;
    }
}
