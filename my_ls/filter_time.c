/*
** EPITECH PROJECT, 2024
** show_time
** File description:
** jsp
*/
#include "my.h"

void organize_files(char **file_list, int i)
{
    int j = 0;
    long time1 = 0;
    long time2 = 0;
    struct stat sb1;
    struct stat sb2;
    char *tmp = file_list[0];

    for (j = 0; j != i; j++) {
        stat(tmp, &sb1);
        stat(file_list[j + 1], &sb2);
        time1 = sb1.st_mtime;
        time2 = sb2.st_mtime;
        if (time1 >= time2)
            tmp = file_list[j + 1];
    }
    for (j = 0; my_strcmp(tmp, file_list[j]) != 0; j++);
    file_list[j] = file_list[i];
    file_list[i] = tmp;
}

void filter_time(char **file_list)
{
    int i = 0;

    for (i = 0; file_list[i] != NULL; i++);
    for (i = i; i != 1; i--)
        organize_files(file_list, i - 1);
}
