/*
** EPITECH PROJECT, 2024
** ls_with_flags
** File description:
** jsp
*/
#include "my.h"

void free_list(char **file_list)
{
    for (int i = 0; file_list[i] != NULL; i++)
        free(file_list[i]);
    free(file_list);
}

char *process_filepath(int ac, char *str)
{
    int count = my_strlen(str);
    char *slash = "/";
    char *filepath;
    DIR *dir;
    struct ls_flags *L_Flag = ls_flags_manager();

    (void)ac;
    if (str[count - 1] != '/') {
        filepath = my_strdup_va(2, str, slash);
        my_strcat(filepath, slash);
    }
    if (str[count - 1] == '/')
        filepath = my_strdup_va(1, str);
    dir = opendir(filepath);
    if (ac - L_Flag[7].count > 1 && dir != NULL &&
    count_filepath(filepath) - 2 != 0) {
        my_putnstr(0, my_strlen(filepath) - 1, filepath);
        my_printf(":\n");
    }
    return filepath;
}

int count_filepath(char *filepath)
{
    int i = 0;
    DIR *directory = opendir(filepath);
    struct dirent *s_directory = readdir(directory);

    while (s_directory != NULL) {
        i++;
        s_directory = readdir(directory);
    }
    closedir(directory);
    return i;
}

void list_filepath(char *filepath, char **file_list)
{
    int i = 0;
    DIR *directory = opendir(filepath);
    struct dirent *s_directory = readdir(directory);

    for (i = 0; s_directory != NULL; i++) {
        file_list[i] = my_strdup_va(2, filepath, s_directory->d_name);
        my_strcat(file_list[i], s_directory->d_name);
        s_directory = readdir(directory);
    }
    file_list[i] = NULL;
    closedir(directory);
}
