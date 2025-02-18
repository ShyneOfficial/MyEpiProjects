/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** jsp
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int j = 0;
    int i = my_strlen(dest);

    for (j = 0; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
