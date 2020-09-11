/*
** EPITECH PROJECT, 2020
** init
** File description:
** button
*/

#include "my.h"
#include "defender.h"

void set_button_position(entity_t **button)
{
    for (int i = 0; i != 4; i++) {
        button[i]->pos.x = 60;
        button[i]->pos.y = i * 100 + i * 100 + 150;
        sfSprite_setPosition(button[i]->sprite, button[i]->pos);
    }
    for (int j = 4; j != 7; j++) {
        button[j]->pos.x = 1920 / 2 - 100;
        button[j]->pos.y = 1200 - j * 150;
        sfSprite_setPosition(button[j]->sprite, button[j]->pos);
    }
    for (int k = 7; k != 9; k++) {
        button[k]->pos.x = -1500 + k * 300;
        button[k]->pos.y = 900;
        sfSprite_setPosition(button[k]->sprite, button[k]->pos);
    }
}

void set_rect_button(entity_t **button)
{
    button[0]->rect.width -= 2;
    button[0]->rect.height--;
    button[7]->rect.width -= 2;
    button[7]->rect.height--;
    button[8]->rect.width -= 2;
    button[8]->rect.height--;
    button[1]->rect.width += 6;
    button[1]->rect.height--;
    button[2]->rect.height--;
    button[2]->rect.width += 12;
    button[3]->rect.width -= 2;
    button[3]->rect.height--;
    button[4]->rect.width -= 2;
    button[4]->rect.height--;
    button[5]->rect.width -= 2;
    button[5]->rect.height--;
    button[6]->rect.width += 7;
    button[6]->rect.height--;
    for (int i = 0; i != 9; i++)
        sfSprite_setTextureRect(button[i]->sprite, button[i]->rect);
}

void init_texture(entity_t **button)
{
    button[0]->texture = sfTexture_createFromFile("image/play_but.png", NULL);
    button[1]->texture = sfTexture_createFromFile("image/but_opt.png", NULL);
    button[2]->texture = sfTexture_createFromFile("image/but_tuto.png", NULL);
    button[3]->texture = sfTexture_createFromFile("image/exit_but.png", NULL);
    button[4]->texture = sfTexture_createFromFile("image/exit_but.png", NULL);
    button[5]->texture = sfTexture_createFromFile("image/menu_but.png", NULL);
    button[6]->texture = sfTexture_createFromFile("image/resume.png", NULL);
    button[7]->texture = sfTexture_createFromFile("image/play_but.png", NULL);
    button[8]->texture = sfTexture_createFromFile("image/exit_but.png", NULL);

    for (int i = 0; i != 9; i++)
        sfSprite_setTexture(button[i]->sprite, button[i]->texture, sfTrue);
    set_rect_button(button);
    set_button_position(button);
}

entity_t **set_button(void)
{
    entity_t **button;
    button = malloc(sizeof(enemy_t *) * 9);
    sfVector2f scale = {7.0, 7.0};

    for (int i = 0; i != 9; i++) {
        button[i] = malloc(sizeof(entity_t));
        button[i]->pos.x = 0;
        button[i]->pos.y = 0;
        button[i]->rect.top = 0;
        button[i]->rect.left = 0;
        button[i]->rect.height = 18;
        button[i]->rect.width = 30;
        button[i]->sprite = sfSprite_create();
        sfSprite_setScale(button[i]->sprite, scale);
    }
    button[0]->clock = sfClock_create();
    init_texture(button);
    return (button);
}
