/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** jsp
*/
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest;

    for (i = 0; src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
