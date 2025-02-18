/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_game
*/
#include "my.h"

void set_menu(void)
{
    sfMusic_stop(MUSIC0.mc);
    BG1.state = 'D';
    SHIP.ps.x = -300;
    SHIP.mv_x = 1;
    BULLET.mv_x = 4;
    BULLET.state = 'D';
    HPBAR.state = 'D';
    sfText_setPosition(TEXT0.text, (sfVector2f){190, 970});
    sfText_setScale(TEXT0.text, (sfVector2f){1, 1});
    sfSprite_setPosition(SHIP.sp, SHIP.ps);
    sfMusic_play(MUSIC1.mc);
}

void set_game(void)
{
    sfMusic_stop(MUSIC1.mc);
    BG1.state = 'A';
    HPBAR.mv_y = 0;
    HPBAR.mv_x = 4;
    SHIP.ps.x = 0;
    sfText_setPosition(TEXT0.text, (sfVector2f){20, 870});
    sfText_setScale(TEXT0.text, (sfVector2f){4, 4});
    sfSprite_setPosition(SHIP.sp, SHIP.ps);
    sfMusic_play(MUSIC0.mc);
}

void loop_game(sfRenderWindow *win, char *score_text)
{
    anim_bg();
    launch_bullet();
    move_bullet();
    anim_bullet_move();
    check_collide();
    move_ship();
    anim_ship_move();
    anim_ship_destroy();
    move_shield();
    anim_shield_block();
    update_hp();
    update_crosshair1(win);
    draw_game_sprites(win, score_text);
    if (HPBAR.mv_x == 0)
        set_menu();
}

void loop_menu(sfRenderWindow *win)
{
    update_cursor(win);
    anim_text();
    draw_menu_sprites(win);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        set_game();
}
