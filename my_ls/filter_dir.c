/*
** EPITECH PROJECT, 2024
** show_dir
** File description:
** jsp
*/
#include "my.h"

static void organize_files(char **file_list, int i)
{
    for (int j = 0; file_list[i + j] != NULL; j++)
        file_list[i + j] = file_list[i + j + 1];
}

void filter_dir(int ac, char **file_list, char *filepath)
{
    char *temp_list[] = {".", NULL};
    struct ls_flags *L_Flag = ls_flags_manager();

    L_Flag[0].count = 1;
    for (int i = 0; file_list[i] != NULL; i++) {
        if (my_strcmp(file_list[i], filepath) == 1) {
            organize_files(file_list, i);
            i--;
        }
    }
    if (ac - L_Flag[7].count == 1 && L_Flag[1].count == 0)
        my_printf(".\n");
    if (ac - L_Flag[7].count == 1 && L_Flag[1].count > 0)
        show_info(-1, 0, temp_list);
}
