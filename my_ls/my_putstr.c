/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** jsp
*/
#include "my.h"

int my_putstr(char *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++)
        j += my_putchar(str[i]);
    return j;
}

int my_putstr_va(va_list list)
{
    int count = 0;

    count += my_putstr(va_arg(list, char *));
    return count;
}
