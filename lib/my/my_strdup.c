/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** string malloc
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!dest)
        return (NULL);
    if (src == NULL)
        return (0);
    my_strcpy(dest, src);
    return (dest);
}
