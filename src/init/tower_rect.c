/*
** EPITECH PROJECT, 2020
** inta
** File description:
** recat
*/

#include "defender.h"

sfIntRect rect(void)
{
    sfIntRect recta;

    recta.top = 2;
    recta.left = 3;
    recta.height = 107;
    recta.width = 36;
    return (recta);
}

sfIntRect set_tower_rect(void)
{
    sfIntRect rect;

    rect.top = 1;
    rect.width = 29;
    rect.height = 39;
    rect.left = 1;
    return (rect);
}

sfIntRect set_tower2_rect(void)
{
    sfIntRect rect;

    rect.top = 1;
    rect.width = 15;
    rect.height = 38;
    rect.left = 1;
    return (rect);
}

sfIntRect rect3(void)
{
    sfIntRect recta;

    recta.top = 0;
    recta.left = 0;
    recta.height = 32;
    recta.width = 32;
    return (recta);
}
