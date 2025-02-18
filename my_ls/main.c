/*
** EPITECH PROJECT, 2024
** main
** File description:
** jsp
*/
#include "my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_ls(int ac, char **av)
{
    char error_char = 0;
    struct ls_flags *L_Flag = ls_flags_manager();

    error_char = check_for_flags(av);
    if (L_Flag[6].count > 0) {
        write(2, "ls: invalid option -- '", 23);
        write(2, &error_char, 1);
        write(2, "'\n", 2);
        L_Flag[8].count = 84;
    } else {
        choose_ls(ac, av);
    }
}

int main(int ac, char **av)
{
    struct ls_flags *L_Flag = ls_flags_manager();

    my_ls(ac, av);
    return L_Flag[8].count;
}
