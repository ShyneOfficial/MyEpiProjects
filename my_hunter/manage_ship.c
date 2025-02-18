/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_ship
*/
#include "my.h"

void move_ship(void)
{
    sfInt64 time = sfClock_getElapsedTime(SHIP.c1).microseconds;

    if (time >= 9000 && SHIP.state == 'A') {
        sfClock_restart(SHIP.c1);
        SHIP.ps = sfSprite_getPosition(SHIP.sp);
        SHIP.ps.x += SHIP.mv_x;
        sfSprite_setPosition(SHIP.sp, SHIP.ps);
    }
    if (SHIP.ps.x >= 1821) {
        SHIP.ps.x = -190;
        SHIP.ps.y = (rand() % 7 + 0) * 100 + 41;
        sfSprite_setPosition(SHIP.sp, SHIP.ps);
        SHIP.mv_x += 0.5;
        BULLET.mv_x += 0.5;
        HPBAR.mv_x -= 1;
        sfSound_play(SOUND2.sd);
    }
}

void anim_ship_move(void)
{
    sfInt64 time = sfClock_getElapsedTime(SHIP.c2).microseconds;
    float x = SHIP.mv_x;

    if (time >= (500000 / x) && SHIP.state == 'A') {
        sfClock_restart(SHIP.c2);
        SHIP.rc.left += 240;
        if (SHIP.rc.left >= 2400)
            SHIP.rc.left = 0;
        sfSprite_setTextureRect(SHIP.sp, SHIP.rc);
    }
}

void anim_ship_destroy(void)
{
    sfInt64 time = sfClock_getElapsedTime(SHIP.c2).microseconds;

    if (time >= 100000 && SHIP.state == 'D') {
        sfClock_restart(SHIP.c2);
        SHIP.rc.left += 240;
        if (SHIP.rc.left >= 4080) {
            SHIP.rc.left = 0;
            SHIP.ps.x = -190;
            SHIP.ps.y = (rand() % 7 + 0) * 100 + 41;
            sfSprite_setPosition(SHIP.sp, SHIP.ps);
            SHIP.state = 'A';
        }
        sfSprite_setTextureRect(SHIP.sp, SHIP.rc);
    }
}

void check_shoot(sfVector2i mouse)
{
    float pos_x0 = SHIP.ps.x;
    float pos_x1 = pos_x0 + SHIP.rc.width;
    float pos_y0 = SHIP.ps.y;
    float pos_y1 = pos_y0 + SHIP.rc.height;
    sfInt64 time = sfClock_getElapsedTime(BG1.c1).microseconds;

    if (time >= 800000 && mouse.x >= pos_x0 && mouse.x <= pos_x1 &&
        mouse.y >= pos_y0 && mouse.y <= pos_y1) {
        sfClock_restart(BG1.c1);
        sfSprite_setPosition(SHIP.sp, SHIP.ps);
        SHIP.mv_x += 0.15;
        BULLET.mv_x += 0.15;
        SHIP.state = 'D';
        SHIP.rc.left = 2400;
        HPBAR.mv_y += 1;
        sfSound_play(SOUND0.sd);
    }
}
