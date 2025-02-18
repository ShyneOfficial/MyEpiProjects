/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** my_printf
*/
#include "my.h"

int print_method(char flag, va_list list)
{
    int i = 0;
    int count = 0;
    struct printf_flags *printf_Flag = printf_flags_manager();

    for (i = 0; printf_Flag[i].flag != 0; i++) {
        if (flag == printf_Flag[i].flag)
            count += printf_Flag[i].function(list);
    }
    return count;
}

int my_printf(char const *format, ...)
{
    int i = 0;
    int count = 0;
    va_list list;

    va_start(list, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            count += print_method(format[i + 1], list);
            i++;
        } else
            count += my_putchar(format[i]);
    }
    va_end(list);
    return count;
}
