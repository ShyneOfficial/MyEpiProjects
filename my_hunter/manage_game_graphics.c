/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_background
*/
#include "my.h"

void anim_bg(void)
{
    sfInt64 time2 = sfClock_getElapsedTime(BG1.c2).microseconds;

    if (time2 >= 120000 && BG1.state == 'A') {
        sfClock_restart(BG1.c2);
        BG1.rc.left += 1821;
        if (BG1.rc.left >= 3642) {
            BG1.rc.left = 0;
            BG1.rc.top += 1024;
        }
        if (BG1.rc.top >= 4096) {
            BG1.rc.left = 0;
            BG1.rc.top = 0;
        }
        sfSprite_setTextureRect(BG1.sp, BG1.rc);
    }
}

void update_hp(void)
{
    if (HPBAR.mv_x > 4)
        HPBAR.mv_x = 4;
    HPBAR.rc.left = HPBAR.mv_x * 300;
    sfSprite_setTextureRect(HPBAR.sp, HPBAR.rc);
}

void update_crosshair1(sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    CROSSHAIR.ps.x = mouse.x - 10;
    CROSSHAIR.ps.y = mouse.y;
    sfSprite_setPosition(CROSSHAIR.sp, CROSSHAIR.ps);
    sfSprite_rotate(CROSSHAIR.sp, 2 * SHIP.mv_x);
}

void update_cursor(sfRenderWindow *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);

    CURSOR.ps.x = mouse.x - 30;
    CURSOR.ps.y = mouse.y;
    sfSprite_setPosition(CURSOR.sp, CURSOR.ps);
}

void anim_text(void)
{
    sfInt64 time = sfClock_getElapsedTime(BG2.c1).microseconds;

    if (BG2.state == 'D' && time >= 300000) {
        sfClock_restart(BG2.c1);
        sfText_setString(TEXT3.text, "Press Space");
        BG2.state = 'A';
    }
    if (BG2.state == 'A' && time >= 1200000) {
        sfClock_restart(BG2.c1);
        sfText_setString(TEXT3.text, " ");
        BG2.state = 'D';
    }
}
