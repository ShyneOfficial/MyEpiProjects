/*
** EPITECH PROJECT, 2024
** show_rev
** File description:
** jsp
*/
#include "my.h"

void filter_rev(char **file_list)
{
    int i = 0;
    int j = 0;
    char *tmp;

    for (i = 0; file_list[i] != NULL; i++);
    for (j = 0; j < (i / 2); j++) {
        tmp = file_list[j];
        file_list[j] = file_list[i - j - 1];
        file_list[i - j - 1] = tmp;
    }
}
