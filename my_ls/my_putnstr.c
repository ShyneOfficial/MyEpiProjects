/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** jsp
*/
#include "my.h"

int my_putnstr(int start, int end, char *str)
{
    int i = 0;
    int j = 0;

    for (i = start; str[i] != '\0' && i < end; i++)
        j += my_putchar(str[i]);
    return j;
}
