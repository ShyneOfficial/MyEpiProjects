/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** jsp
*/
#include "my.h"

char count_flags(char *flags)
{
    int j = 0;
    int i = 1;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (i = 1; flags[i] != '\0'; i++) {
        for (j = 0; flags[i] != L_Flag[j].flag && L_Flag[j].flag != '?'; j++);
        L_Flag[j].count += 1;
        if (j == 6)
            return flags[i];
    }
    return 0;
}

char check_for_flags(char **av)
{
    char error_char = 0;
    int i = 1;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (i = 1; av[i] != NULL; i++) {
        if (av[i][0] == '-' && av[i][1] != 0) {
            L_Flag[7].count += 1;
            error_char = count_flags(av[i]);
        }
        if (error_char != 0)
            return error_char;
    }
    return 0;
}

void choose_ls(int ac, char **av)
{
    char *filepath = ".";
    struct ls_flags *L_Flag = ls_flags_manager();

    if (ac - L_Flag[7].count == 1)
        simple_ls(ac, filepath);
    if (ac - L_Flag[7].count > 1)
        complex_ls(ac, av);
}

void simple_ls(int ac, char *str)
{
    int files_count;
    char *filepath = process_filepath(ac, str);
    char **file_list;
    struct ls_flags *L_Flag = ls_flags_manager();

    if (L_Flag[2].count > 0 && ac - L_Flag[7].count == 1) {
        my_putnstr(0, my_strlen(filepath) - 1, filepath);
        my_printf(":\n");
    }
    files_count = count_filepath(str);
    file_list = malloc(sizeof(char *) * (files_count + 1));
    list_filepath(filepath, file_list);
    process_flags_directories(ac, file_list, filepath);
    free_list(file_list);
}

void complex_ls(int ac, char **av)
{
    int files_count = count_av(av);
    char **file_list = malloc(sizeof(char *) * (files_count + 1));
    struct ls_flags *L_Flag = ls_flags_manager();

    list_av(av, file_list);
    error_managment(av);
    if (files_count > 0)
        process_flags_files(ac, file_list);
    if (L_Flag[3].count == 0)
        display_directories(ac, files_count, av);
    free_list(file_list);
}
