/*
** EPITECH PROJECT, 2020
** init
** File description:
** hud
*/

#include "defender.h"

void set_back_hud(game_t *game)
{
    sfSprite *sprite_tit = sfSprite_create();
    sfTexture *texture_tit = sfTexture_createFromFile("image/Hud.png", NULL);
    sfVector2f pos = {1620, 30};
    sfVector2f scale = {1.5, 1.5};

    sfSprite_setTexture(sprite_tit, texture_tit, sfFalse);
    sfSprite_setScale(sprite_tit, scale);
    sfSprite_setPosition(sprite_tit, pos);
    sfRenderWindow_drawSprite(game->core->window, sprite_tit, NULL);
}

void draw_score(game_t *game)
{
    sfVector2f pos = {1710, 50};

    if (sfTime_asSeconds
    (sfClock_getElapsedTime(game->hud[1]->test)) >= 1.5) {
        sfClock_restart(game->hud[1]->test);
        sfText_setString(game->hud[1]->text,
        my_itoa(game->hud[1]->score));
        game->hud[1]->score += 5;
    }
    sfText_setPosition(game->hud[1]->text, game->hud[1]->pos);
    set_back_hud(game);
    sfRenderWindow_drawText(game->core->window, game->hud[1]->text, NULL);
    sfText_setString(game->hud[2]->text,
    my_itoa(game->base->gold));
    sfText_setPosition(game->hud[2]->text, pos);
    sfRenderWindow_drawText(game->core->window, game->hud[2]->text, NULL);
    sfRenderWindow_drawSprite(game->core->window, game->hud[2]->sprite, NULL);
}

void init_tower_buttons(hud_t **hud)
{
    hud[0] = malloc(sizeof(hud_t));

    hud[0]->tower_pos.x = 820;
    hud[0]->tower_pos.y = 900;
    hud[0]->tower_sca.x = 4;
    hud[0]->tower_sca.y = 4;
    hud[0]->tower_rect.left = 1;
    hud[0]->tower_rect.top = 1;
    hud[0]->tower_rect.width = 103;
    hud[0]->tower_rect.height = 56;
    hud[0]->tower_spr = sfSprite_create();
    hud[0]->clock = sfClock_create();
    hud[0]->tower_tex = sfTexture_createFromFile("image/new_ts.png", NULL);
    sfSprite_setTexture(hud[0]->tower_spr, hud[0]->tower_tex, sfTrue);
    sfSprite_setTextureRect(hud[0]->tower_spr, hud[0]->tower_rect);
    sfSprite_setPosition(hud[0]->tower_spr, hud[0]->tower_pos);
    sfSprite_setScale(hud[0]->tower_spr, hud[0]->tower_sca);
}

void init_hud_texture(hud_t **hud)
{
    sfVector2f pos = {1780, 39};
    sfVector2f posi = hud[1]->pos;

    posi.x -= 185;
    posi.y -= 52;
    hud[1]->tex = sfTexture_createFromFile("image/life.png", NULL);
    hud[2]->tex = sfTexture_createFromFile("image/coins.png", NULL);
    sfSprite_setTexture(hud[1]->sprite, hud[1]->tex, sfTrue);
    sfSprite_setTexture(hud[2]->sprite, hud[2]->tex, sfTrue);
    sfSprite_setPosition(hud[1]->sprite, pos);
    sfSprite_setPosition(hud[2]->sprite, pos);
}

hud_t **set_hud(void)
{
    hud_t **hud = malloc(sizeof(hud_t *) * 4);
    sfVector2f scale = {0.9, 0.9};

    init_tower_buttons(hud);
    for (int i = 1; i != 4; i++) {
        hud[i] = malloc(sizeof(hud_t));
        hud[i]->text = sfText_create();
        hud[i]->test = sfClock_create();
        hud[i]->font = sfFont_createFromFile("font/pixel-legit.ttf");
        hud[i]->sprite = sfSprite_create();
        hud[i]->pos.x = 1835;
        hud[i]->pos.y = 50;
        hud[i]->score = 0;
        hud[i]->coin = 0;
        sfText_setFont(hud[i]->text, hud[i]->font);
        sfText_setCharacterSize(hud[i]->text, 20);
        sfSprite_setScale(hud[i]->sprite, scale);
    }
    init_hud_texture(hud);
    return (hud);
}
