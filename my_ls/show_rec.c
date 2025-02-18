/*
** EPITECH PROJECT, 2024
** show_sub
** File description:
** jsp
*/
#include "my.h"

void show_rec(int ac, char *filepath, char **file_list)
{
    int offset = my_strlen(filepath);
    struct stat sb;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (int i = 0; file_list[i] != NULL; i++) {
        stat(file_list[i], &sb);
        if (S_ISDIR(sb.st_mode) &&
            (my_strcmp(file_list[i] + offset, ".") == 1) &&
            (my_strcmp(file_list[i] + offset, "..") == 1) &&
            opendir(file_list[i]) != NULL) {
            my_printf("\n");
            simple_ls(ac, file_list[i]);
        }
        if (S_ISDIR(sb.st_mode) && opendir(file_list[i]) == NULL) {
            write(2, "ls: cannot open directory '", 27);
            write(2, file_list[i], my_strlen(file_list[i]));
            write(2, "': Permission denied\n", 21);
            L_Flag[8].count = 84;
        }
    }
}
