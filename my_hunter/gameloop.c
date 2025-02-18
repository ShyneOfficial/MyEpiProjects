/*
** EPITECH PROJECT, 2024
** main
** File description:
** jsp
*/
#include "my.h"

void chec_game_evt(sfRenderWindow *win, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(win, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (evt.type == sfEvtMouseButtonPressed)
            check_shoot(sfMouse_getPositionRenderWindow(win));
    }
}

void initialize_game(sfRenderWindow *win)
{
    sfRenderWindow_setMouseCursorVisible(win, sfFalse);
    sfRenderWindow_setFramerateLimit(win, 60);
    initialize_ship();
    initialize_bullet();
    initialize_background1();
    initialize_shield();
    initialize_hp();
    initialize_ship_dest_sound();
    initialize_bullet_dest_sound();
    initialize_hp_lost();
    initialize_crosshair1();
    initialize_text();
}

void initialize_menu(void)
{
    initialize_musics();
    sfMusic_setVolume(MUSIC0.mc, 20);
    sfMusic_setLoop(MUSIC0.mc, sfTrue);
    sfMusic_setVolume(MUSIC1.mc, 20);
    sfMusic_setLoop(MUSIC1.mc, sfTrue);
    sfMusic_play(MUSIC1.mc);
    initialize_background2();
    initialize_cursor();
}

int gameloop(sfVideoMode mode, char *score_text, sfEvent evt)
{
    sfRenderWindow *win;

    win = sfRenderWindow_create(mode, "Space_Hunt", sfDefaultStyle, NULL);
    if (error_management_png() == 1 || error_management_mp3() == 1)
        return 1;
    init_game(win);
    if (error_management_sp1(win) == 1 || error_management2() == 1 ||
        error_management_sp2() == 1)
        return 1;
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_display(win);
        chec_game_evt(win, evt);
        if (BG1.state == 'A')
            loop_game(win, score_text);
        if (BG1.state == 'D')
            loop_menu(win);
    }
    fini_game(win);
    return 0;
}
