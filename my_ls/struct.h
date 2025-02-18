/*
** EPITECH PROJECT, 2024
** ls.h
** File description:
** jsp
*/
#ifndef STRUCT_H
    #define STRUCT_H
    #include "my.h"

struct file_rights {
    char right_char;
    char no_right_char;
    unsigned int right;
};

struct file_type {
    char type;
    unsigned int stat_type;
};

struct ls_flags {
    char flag;
    int count;
};

struct printf_flags {
    char flag;
    int (*function)(va_list);
};

#endif
