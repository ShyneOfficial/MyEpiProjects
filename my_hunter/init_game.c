/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** init_game
*/
#include "my.h"

game_t *game(void)
{
    static game_t game;

    return &game;
}

void init_game(sfRenderWindow *win)
{
    GAME->sprite = malloc(sizeof(sprite_t) * 8);
    GAME->sound = malloc(sizeof(sound_t) * 3);
    GAME->music = malloc(sizeof(music_t) * 2);
    GAME->text = malloc(sizeof(text_t) * 6);
    initialize_game(win);
    initialize_menu();
}

void fini_game(sfRenderWindow *win)
{
    destroy_sprites();
    destroy_sounds();
    destroy_text();
    sfRenderWindow_destroy(win);
    free(GAME->sprite);
    free(GAME->sound);
    free(GAME->music);
    free(GAME->text);
}
