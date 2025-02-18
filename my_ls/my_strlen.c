/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** jsp
*/
int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
