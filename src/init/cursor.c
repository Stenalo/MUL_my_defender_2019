/*
** EPITECH PROJECT, 2020
** init
** File description:
** cursor
*/

#include "defender.h"

cursor_t *set_cursor(void)
{
    cursor_t *cursor;

    cursor = malloc(sizeof(*cursor));
    cursor->pos.x = 0;
    cursor->pos.y = 0;
    cursor->click = false;
    cursor->hold = false;
    return (cursor);
}
