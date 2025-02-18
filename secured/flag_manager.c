/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** flag_manager
*/
#include "my.h"

struct printf_flags *printf_flags_manager(void)
{
    static struct printf_flags printf_Flag[] = {
        {'c', &my_putchar_va},
        {'s', &my_putstr_va},
        {'d', &my_putnbr_va},
        {'l', &my_putlong_va},
        {0, NULL}
    };

    return printf_Flag;
}
