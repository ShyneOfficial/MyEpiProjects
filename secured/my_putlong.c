/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** my_putlong
*/
#include "my.h"

int my_putlong(long int lg)
{
    int i = 0;
    int j = 1;

    if (lg < 0) {
        lg = -lg;
        i += my_putchar('-');
    }
    for (j = 1; (lg / j) > 9; j *= 10);
    for (j = j; j > 0; j /= 10)
        i += my_putchar('0' + (lg / j) % 10);
    return i;
}

int my_putlong_va(va_list list)
{
    int count = 0;

    count += my_putlong(va_arg(list, long));
    return count;
}
