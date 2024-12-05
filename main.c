/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** main
*/
#include "my.h"

void help(void)
{
    my_putstr("A long time ago in a galaxy far, far away,\n");
    my_putstr("there was a planet called the Earth.\n\n");
    my_putstr("Life here was abundant, and countless \n");
    my_putstr("species lived in countless landscapes \n");
    my_putstr("while enjoying countless resources.\n\n");
    my_putstr("Unfortunately, this attracted many other \n");
    my_putstr("planets who coveted the resources that \n");
    my_putstr("could be found everywhere around the globe.\n\n");
    my_putstr("Your mission, youngling, is to protect your\n");
    my_putstr("cherished home from these wicked invaders \n");
    my_putstr("and put an end to this tyranny.\n\n");
    my_putstr("Make use of your strongest Mouse Click \n");
    my_putstr("turret to destroy the incoming spaceships.\n\n");
    my_putstr("But be careful! They are heavily armed and \n");
    my_putstr("might end up launching missiles towards your \n");
    my_putstr("base!\n\n");
    my_putstr("Block them by nimbly maneuvering your own spaceship \n");
    my_putstr("with the Z and S button on the command board.\n\n");
    my_putstr("However, you are by no mean invincible!.\n");
    my_putstr("Be mindful of it at all times, and good luck soldier!\n");
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1821, 1080, 32};
    sfEvent evt;
    char score_text[7];

    if (ac == 1) {
        if (gameloop(mode, score_text, evt) == 1)
            return 84;
    } else if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        help();
    return 0;
}
