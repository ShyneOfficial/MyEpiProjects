/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** allocate memory and copies the string given as argument
*/

#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++);
    return count;
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *mem = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (i = 0; src[i] != '\0'; i++) {
        mem[i] = src[i];
    }
    mem[i] = '\0';
    return mem;
}
