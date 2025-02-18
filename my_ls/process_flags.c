/*
** EPITECH PROJECT, 2024
** process_flags
** File description:
** jsp
*/
#include "my.h"

void process_flags_files(int ac, char **file_list)
{
    struct ls_flags *L_Flag = ls_flags_manager();

    if (L_Flag[5].count > 0)
        filter_time(file_list);
    if (L_Flag[4].count > 0)
        filter_rev(file_list);
    if (L_Flag[1].count > 0)
        show_info(ac, 0, file_list);
    if (L_Flag[1].count == 0) {
        for (int i = 0; file_list[i] != NULL; i++)
            my_printf("%s\n", file_list[i]);
    }
}

void process_flags_directories(int ac, char **file_list, char *filepath)
{
    int offset = my_strlen(filepath);
    struct ls_flags *L_Flag = ls_flags_manager();

    if (L_Flag[3].count > 0)
        filter_dir(ac, file_list, filepath);
    if (L_Flag[0].count == 0)
        filter_hid(offset, file_list);
    if (L_Flag[5].count > 0 && ac - L_Flag[7].count > 0 &&
    L_Flag[3].count == 0 && file_list[0] != NULL)
        filter_time(file_list);
    if (L_Flag[4].count > 0)
        filter_rev(file_list);
    if (L_Flag[1].count > 0 && L_Flag[3].count == 0)
        show_info(ac, offset, file_list);
    if (L_Flag[1].count == 0) {
        for (int i = 0; file_list[i] != NULL; i++)
            my_printf("%s\n", file_list[i] + offset);
    }
    if (L_Flag[2].count > 0)
        show_rec(ac, filepath, file_list);
}
