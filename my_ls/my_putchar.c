/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** jsp
*/
#include "my.h"

int my_putchar(char c)
{
    int count = 0;

    count = write(1, &c, 1);
    return count;
}

int my_putchar_va(va_list list)
{
    int count = 0;

    count = my_putchar(va_arg(list, int));
    return count;
}
