/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** jsp
*/
#include "my.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
