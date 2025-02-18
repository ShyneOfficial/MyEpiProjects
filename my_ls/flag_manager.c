/*
** EPITECH PROJECT, 2024
** ls_flags_manager
** File description:
** jsp
*/
#include "struct.h"

struct file_rights *file_rights_manager(void)
{
    static struct file_rights F_Right[] = {
        {'r', '-', S_IRUSR},
        {'w', '-', S_IWUSR},
        {'x', '-', S_IXUSR},
        {'r', '-', S_IRGRP},
        {'w', '-', S_IWGRP},
        {'x', '-', S_IXGRP},
        {'r', '-', S_IROTH},
        {'w', '-', S_IWOTH},
        {'x', '-', S_IXOTH},
        {0, 0, 0}
    };

    return F_Right;
}

struct file_type *file_type_manager(void)
{
    static struct file_type F_Type[] = {
        {'d', __S_IFDIR},
        {'c', __S_IFCHR},
        {'b', __S_IFBLK},
        {'-', __S_IFREG},
        {'p', __S_IFIFO},
        {'l', __S_IFLNK},
        {0, 0}
    };

    return F_Type;
}

struct ls_flags *ls_flags_manager(void)
{
    static struct ls_flags L_Flag[] = {
        {'a', 0},
        {'l', 0},
        {'R', 0},
        {'d', 0},
        {'r', 0},
        {'t', 0},
        {'?', 0},
        {'-', 0},
        {'*', 0}
        };

    return L_Flag;
}

struct printf_flags *printf_flags_manager(void)
{
    static struct printf_flags P_Flag[] = {
        {'c', &my_putchar_va},
        {'s', &my_putstr_va},
        {'d', &my_put_nbr_va},
        {'l', &my_put_long_va},
        {0, NULL}
    };

    return P_Flag;
}
