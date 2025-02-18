/*
** EPITECH PROJECT, 2025
** B-CPE-110-RUN-1-1-secured-brandon-jean-samuel.begue
** File description:
** hash
*/
#include "hashtable.h"

int nbrlen(int nb)
{
    int i = 0;
    int j = 1;

    if (nb < 0) {
        nb = -nb;
        i++;
    }
    for (j = 1; (nb / j) > 9; j *= 10);
    for (j = j; j > 0; j /= 10)
        i++;
    return i;
}

int count_key(char *key, int len)
{
    int count = 0;

    if (!key)
        return 0;
    for (int i = 0; key[i]; i++) {
        if (key[i + 1]) {
            count += (key[i] + key[i + 1] / len);
        } else {
            count += key[i] - key[i - 1] * len;
        }
    }
    count *= count;
    count *= (count < 0) ? -1 : 1;
    return count;
}

int get_hash(int r, int offset, char *key, int len)
{
    int hash = 0;
    int count = count_key(key, len);
    int nb_len = nbrlen(count);
    int i = 0;
    int j = 1;
    float tmp = 0;

    for (int k = 0; k != r; k++) {
        for (i = 0; i != nb_len - offset - k; i++) {
            tmp = count;
            tmp /= j;
            j *= 10;
        }
        j = 1;
        hash = (hash * 10) + ((int)tmp % 10);
    }
    return hash;
}

int hash(char *key, int len)
{
    int hash = 0;
    int count = count_key(key, len);
    int nb_len = nbrlen(count);
    int r = nb_len / 3;
    float tmp = nb_len;
    int offset = 0;

    if (!key)
        return 84;
    tmp /= 3;
    if (tmp - r > 0)
        offset = r + 1;
    else
        offset = r;
    if (r == 0)
        r = 1;
    hash = get_hash(r, offset, key, len);
    return hash;
}
