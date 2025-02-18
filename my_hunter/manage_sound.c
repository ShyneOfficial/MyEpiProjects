/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** initialize_sound
*/
#include "my.h"

void initialize_ship_dest_sound(void)
{
    SOUND0.sb = sfSoundBuffer_createFromFile("shipDestSound.mp3");
    SOUND0.sd = sfSound_create();
    sfSound_setBuffer(SOUND0.sd, SOUND0.sb);
}

void initialize_bullet_dest_sound(void)
{
    SOUND1.sb = sfSoundBuffer_createFromFile("bulletDestSound.mp3");
    SOUND1.sd = sfSound_create();
    sfSound_setBuffer(SOUND1.sd, SOUND1.sb);
}

void initialize_hp_lost(void)
{
    SOUND2.sb = sfSoundBuffer_createFromFile("hpLost.mp3");
    SOUND2.sd = sfSound_create();
    sfSound_setBuffer(SOUND2.sd, SOUND2.sb);
}

void destroy_sounds(void)
{
    sfMusic_destroy(MUSIC0.mc);
    sfMusic_destroy(MUSIC1.mc);
    for (int i = 0; i != 2; i++) {
        sfSoundBuffer_destroy(GAME->sound[i].sb);
        sfSound_destroy(GAME->sound[i].sd);
    }
}
