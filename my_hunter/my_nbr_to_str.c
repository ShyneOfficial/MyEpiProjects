/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** my_nbr_to_str
*/
#include "my.h"

char *my_nbr_to_str(char *str, int nb)
{
    int i = my_nbrlen(nb);
    int j = 1;

    i = 0;
    if (nb < 0) {
        nb = -nb;
        str[i] += '-';
        i += 1;
    }
    for (j = 1; (nb / j) > 9; j *= 10);
    for (j = j; j > 0; j /= 10) {
        str[i] = (char)(48 + (nb / j) % 10);
        i += 1;
    }
    str[i] = '\0';
    return str;
}
