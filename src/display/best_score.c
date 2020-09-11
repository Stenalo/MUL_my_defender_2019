/*
** EPITECH PROJECT, 2020
** display
** File description:
** best score
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "defender.h"

char *get_file(char *path)
{
    FILE *new = fopen(path, "w+");
    size_t read = 0;
    size_t size = 0;
    char *buffer = NULL;

    for (int j = 0; (int)size != -1; j++)
        size = getline(&buffer, &read, new);
    fclose(new);
    return (buffer);
}

char *update_best_score(char *buff, game_t *game)
{
    FILE *new = fopen("score/score.txt", "w+");
    char *tmp = my_itoa(game->hud[1]->score);

    if (!tmp)
        return (NULL);
    fwrite(tmp, my_strlen(tmp), 1, new);
    buff = my_strcpy(buff, tmp);
    fclose(new);
    return (buff);
}

void draw_end_buttons(game_t *game)
{
    for (int i = 7; i < 9; i++) {
        sfRenderWindow_drawSprite(game->core->window,
        game->button[i]->sprite, NULL);
    }
}

void draw_back_end(game_t *game)
{
    sfSprite *sprite_tit = sfSprite_create();
    sfTexture *texture_tit = sfTexture_createFromFile("image/ende.jpg", NULL);

    sfSprite_setTexture(sprite_tit, texture_tit, sfFalse);
    sfRenderWindow_drawSprite(game->core->window, sprite_tit, NULL);
}

void draw_best_score(game_t *game)
{
    char *buff = get_file("score/score.txt");

    if (!buff)
        return;
    if (my_getnbr(buff) < game->hud[1]->score)
        update_best_score(buff, game);
    sfText_setString(game->hud[3]->text, buff);
    game->hud[3]->pos.x = 110;
    game->hud[3]->pos.y = 320;
    game->hud[1]->pos.x = 880;
    game->hud[1]->pos.y = 320;
    sfText_setCharacterSize(game->hud[3]->text, 100);
    sfText_setCharacterSize(game->hud[1]->text, 100);
    sfText_setPosition(game->hud[3]->text, game->hud[3]->pos);
    sfText_setPosition(game->hud[1]->text, game->hud[1]->pos);
    draw_back_end(game);
    draw_end_buttons(game);
    sfRenderWindow_drawText(game->core->window, game->hud[1]->text, NULL);
    sfRenderWindow_drawText(game->core->window, game->hud[3]->text, NULL);
}