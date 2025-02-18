/*
** EPITECH PROJECT, 2024
** ls_with_flags
** File description:
** jsp
*/
#include "my.h"

void error_managment(char **av)
{
    int error = 0;
    struct stat sb;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (int i = 1; av[i] != NULL; i++) {
        error = (av[i][0] == '-' && av[i][1] != 0) ? 0 : stat(av[i], &sb);
        if (error == -1) {
            write(2, "ls: cannot access '", 19);
            write(2, av[i], my_strlen(av[i]));
            write(2, "': No such file or directory\n", 29);
            L_Flag[8].count = 84;
        }
    }
}

int count_av(char **av)
{
    int error = 0;
    int files_count = 0;
    struct stat sb;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (int i = 1; av[i] != NULL; i++) {
        error = stat(av[i], &sb);
        if (S_ISDIR(sb.st_mode) && L_Flag[3].count > 0 && error == 0)
            files_count++;
        if (S_ISREG(sb.st_mode) && error == 0)
            files_count++;
    }
    return files_count;
}

void list_av(char **av, char **file_list)
{
    int error = 0;
    int files_count = 0;
    struct stat sb;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (int i = 1; av[i] != NULL; i++) {
        error = stat(av[i], &sb);
        if (S_ISDIR(sb.st_mode) && L_Flag[3].count > 0 && error == 0) {
            file_list[files_count] = my_strdup_va(1, av[i]);
            files_count++;
        }
        if (S_ISREG(sb.st_mode) && error == 0) {
            file_list[files_count] = my_strdup_va(1, av[i]);
            files_count++;
        }
    }
    file_list[files_count] = NULL;
}

void display_directories(int ac, int files_count, char **av)
{
    int i = 0;
    int error = 0;
    struct stat sb;

    for (i = 1; av[i][0] == '-' && av[i][1] != 0; i++);
    stat(av[i], &sb);
    if (S_ISDIR(sb.st_mode) && files_count > 0)
        my_printf("\n");
    for (i = i; av[i] != NULL; i++) {
        error = stat(av[i], &sb);
        if (S_ISDIR(sb.st_mode) && error == 0 && opendir(av[i]) != NULL)
            simple_ls(ac, av[i]);
        stat(av[i + 1], &sb);
        if (av[i + 1] != NULL && av[i + 1][0] != '-' && S_ISDIR(sb.st_mode))
            my_printf("\n");
    }
}
