/*
** EPITECH PROJECT, 2024
** my_strdup_va
** File description:
** jsp
*/
#include "my.h"

char *my_strdup_va(int ac, char *src, ...)
{
    int i = my_strlen(src);
    char *dest;
    va_list list;

    va_start(list, src);
    for (int j = 1; j != ac; j++)
        i += my_strlen(va_arg(list, char *));
    dest = malloc(sizeof(char) * (i + 1));
    my_strcpy(dest, src);
    va_end(list);
    return dest;
}
