/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** jsp
*/
#include "my.h"

int my_put_nbr(int nb)
{
    int i = 0;
    int j = 1;

    if (nb < 0) {
        nb = -nb;
        i += my_putchar('-');
    }
    for (j = 1; (nb / j) > 9; j *= 10);
    for (j = j; j > 0; j /= 10)
        i += my_putchar('0' + (nb / j) % 10);
    return i;
}

int my_put_nbr_va(va_list list)
{
    int count = 0;

    count += my_put_nbr(va_arg(list, int));
    return count;
}
