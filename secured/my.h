/*
** EPITECH PROJECT, 2025
** MY_H
** File description:
** MY_H
*/

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>

struct printf_flags {
    char flag;
    int (*function)(va_list);
};

char *my_strdup(char const *str);
int my_printf(char const *format, ...);
int my_putchar(char c);
int my_putchar_va(va_list list);
int my_putstr(char *str);
int my_putstr_va(va_list list);
int my_putnbr(int nb);
int my_putnbr_va(va_list list);
int my_putlong(long int lg);
int my_putlong_va(va_list list);
struct printf_flags *printf_flags_manager(void);


#endif /* !MY_H */
