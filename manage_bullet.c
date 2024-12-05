/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_bullet
*/
#include "my.h"

void launch_bullet(void)
{
    sfInt64 time = sfClock_getElapsedTime(BULLET.c1).microseconds;

    if (time >= (20000000 / SHIP.mv_x)) {
        BULLET.ps.x = SHIP.ps.x + (SHIP.rc.width / 2);
        BULLET.ps.y = SHIP.ps.y + (SHIP.rc.height / 2) - 20;
        sfSprite_setPosition(BULLET.sp, BULLET.ps);
        BULLET.state = 'A';
        sfClock_restart(BULLET.c1);
    }
}

void move_bullet(void)
{
    sfInt64 time = sfClock_getElapsedTime(BULLET.c1).microseconds;

    if (time >= 9000 && BULLET.state == 'A') {
        sfClock_restart(BULLET.c1);
        BULLET.ps = sfSprite_getPosition(BULLET.sp);
        BULLET.ps.x += BULLET.mv_x;
        sfSprite_setPosition(BULLET.sp, BULLET.ps);
    }
    if (BULLET.ps.x >= 1821) {
        BULLET.ps.x = -190;
        BULLET.ps.y = rand() % 790 + 100;
        sfSprite_setPosition(BULLET.sp, BULLET.ps);
        BULLET.mv_x += 2.5;
        BULLET.state = 'D';
        HPBAR.mv_x -= 1;
        sfSound_play(SOUND2.sd);
    }
}

void anim_bullet_move(void)
{
    sfInt64 time = sfClock_getElapsedTime(BULLET.c2).microseconds;

    if (time >= 100000 && BULLET.state == 'A') {
        sfClock_restart(BULLET.c2);
        BULLET.rc.left += 80;
        if (BULLET.rc.left >= 240)
            BULLET.rc.left = 0;
        sfSprite_setTextureRect(BULLET.sp, BULLET.rc);
    }
}

void check_collide(void)
{
    sfInt64 time = sfClock_getElapsedTime(SHIELD.c2).microseconds;
    float posBu_x = BULLET.ps.x + 80;
    float posSh_x0 = SHIELD.ps.x;
    float posSh_x1 = SHIELD.ps.x + SHIELD.rc.width;
    float posBu_y = BULLET.ps.y + 20;
    float posSh_y0 = SHIELD.ps.y;
    float posSh_y1 = SHIELD.ps.y + SHIELD.rc.height;

    if (time >= 1000000 && posBu_x >= posSh_x0 && posBu_x <= posSh_x1 &&
        posBu_y >= posSh_y0 && posBu_y <= posSh_y1) {
        sfClock_restart(SHIELD.c2);
        SHIELD.state = 'S';
        HPBAR.mv_x += 1;
    }
}
