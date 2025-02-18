/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_music
*/
#include "my.h"

void initialize_musics(void)
{
    MUSIC0.mc = sfMusic_createFromFile("gameMusic.ogg");
    MUSIC1.mc = sfMusic_createFromFile("menuMusic.ogg");
}
