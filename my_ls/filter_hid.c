/*
** EPITECH PROJECT, 2024
** show_hidden
** File description:
** jsp
*/
#include "my.h"

static void organize_files(char **file_list, int i)
{
    for (int j = 0; file_list[i + j] != NULL; j++)
        file_list[i + j] = file_list[i + j + 1];
}

void filter_hid(int offset, char **file_list)
{
    for (int i = 0; file_list[i] != NULL; i++) {
        if (file_list[i][0 + offset] == '.') {
            organize_files(file_list, i);
            i--;
        }
    }
}
