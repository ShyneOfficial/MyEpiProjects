/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** jsp
*/
#ifndef MY_H
    #define MY_H
    #include <stddef.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <time.h>
    #include <pwd.h>
    #include "struct.h"

char check_for_flags(char **av);
int count_av(char **av);
int count_filepath(char *filepath);
int my_printf(char const *format, ...);
int my_put_nbr(int nb);
int my_put_nbr_va(va_list list);
int my_put_long(long lg);
int my_put_long_va(va_list list);
int my_putchar(char c);
int my_putchar_va(va_list list);
int my_putnstr(int start, int end, char *str);
int my_putstr(char *str);
int my_putstr_va(va_list list);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup_va(int ac, char *src, ...);
char *my_strdup(char const *src);
char *process_filepath(int ac, char *str);
void choose_ls(int ac, char **av);
void complex_ls(int ac, char **av);
void display_directories(int ac, int files_count, char **av);
void error_managment(char **av);
void filter_dir(int ac, char **file_list, char *filepath);
void filter_hid(int offset, char **file_list);
void filter_rev(char **file_list);
void filter_time(char **file_list);
void free_list(char **file_list);
void list_av(char **av, char **file_list);
void list_filepath(char *filepath, char **file_list);
void my_ls(int ac, char **av);
void process_flags_directories(int ac, char **file_list, char *filepath);
void process_flags_files(int ac, char **file_list);
void rights_checker(char *filepath);
void show_info(int ac, int offset, char **file_list);
void show_rec(int ac, char *filepath, char **file_list);
void simple_ls(int ac, char *filepath);
void type_checker(char *filepath);
struct file_rights *file_rights_manager(void);
struct file_type *file_type_manager(void);
struct ls_flags *ls_flags_manager(void);
struct printf_flags *printf_flags_manager(void);

#endif
