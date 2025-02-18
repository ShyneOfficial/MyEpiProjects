/*
** EPITECH PROJECT, 2024
** show_info_all
** File description:
** jsp
*/
#include "my.h"
#include <grp.h>

void type_display(char *file)
{
    int j = 0;
    struct stat sb;
    struct file_type *F_Type = file_type_manager();

    stat(file, &sb);
    for (j = 0; F_Type[j].type != 0; j++) {
        if ((sb.st_mode & __S_IFMT) == F_Type[j].stat_type)
            my_putchar(F_Type[j].type);
    }
}

void rights_display(char *file)
{
    int j = 0;
    struct stat sb;
    struct file_rights *F_Right = file_rights_manager();

    stat(file, &sb);
    for (j = 0; F_Right[j].right_char != 0; j++) {
        if (sb.st_mode & __S_ISVTX && j == 8)
            my_putchar('t');
        if ((sb.st_mode & F_Right[j].right) == F_Right[j].right && j == 8 &&
        (sb.st_mode & __S_ISVTX) != __S_ISVTX)
            my_putchar(F_Right[j].right_char);
        if ((sb.st_mode & F_Right[j].right) != F_Right[j].right && j == 8 &&
        (sb.st_mode & __S_ISVTX) != __S_ISVTX)
            my_putchar(F_Right[j].no_right_char);
        if ((sb.st_mode & F_Right[j].right) == F_Right[j].right && j != 8)
            my_putchar(F_Right[j].right_char);
        if ((sb.st_mode & F_Right[j].right) != F_Right[j].right && j != 8)
            my_putchar(F_Right[j].no_right_char);
    }
}

void count_blocks(int ac, int offset, char **file_list)
{
    long total = 0;
    struct stat sb;
    struct ls_flags *L_Flag = ls_flags_manager();

    for (int i = 0; file_list[i] != NULL; i++) {
        stat(file_list[i], &sb);
        total += sb.st_blocks;
    }
    total /= 2;
    if (offset > 0 && ac - L_Flag[7].count > 0)
        my_printf("total %l\n", total);
}

void show_info(int ac, int offset, char **file_list)
{
    char *time;
    struct stat sb;
    struct passwd *pw;
    struct group *gr;

    count_blocks(ac, offset, file_list);
    for (int i = 0; file_list[i] != NULL; i++) {
        stat(file_list[i], &sb);
        time = ctime(&sb.st_mtime);
        pw = getpwuid(sb.st_uid);
        gr = getgrgid(sb.st_gid);
        type_display(file_list[i]);
        rights_display(file_list[i]);
        my_printf(" %l %s ", sb.st_nlink, pw->pw_name);
        my_printf("%s %l ", gr->gr_name, sb.st_size);
        my_putnstr(4, 16, time);
        my_printf(" %s\n", file_list[i] + offset);
    }
}
