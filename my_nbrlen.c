/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** my_nbrlen
*/
int my_nbrlen(int nb)
{
    int i = 0;
    int j = 1;

    if (nb < 0) {
        nb = -nb;
        i += 1;
    }
    i += 1;
    for (j = 1; (nb / j) > 9; j *= 10)
        i += 1;
    return i;
}
