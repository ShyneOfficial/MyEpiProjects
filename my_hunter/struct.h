/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** jsp
*/
#ifndef STRUCT_H
    #define STRUCT_H
    #include "my.h"

typedef struct sprite_s {
    sfTexture *tx;
    sfSprite *sp;
    sfIntRect rc;
    sfVector2f ps;
    sfClock *c1;
    sfClock *c2;
    float mv_x;
    float mv_y;
    char state;
}sprite_t;

typedef struct sound_s {
    sfSoundBuffer *sb;
    sfSound *sd;
}sound_t;

typedef struct music_s {
    sfMusic *mc;
}music_t;

typedef struct text_s {
    sfText *text;
}text_t;

typedef struct game_s {
    sprite_t *sprite;
    sound_t *sound;
    music_t *music;
    text_t *text;
}game_t;

#endif
