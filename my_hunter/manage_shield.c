/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_shield
*/
#include "my.h"

void move_shield(void)
{
    sfInt64 time = sfClock_getElapsedTime(SHIELD.c1).microseconds;
    float pos_y = SHIELD.ps.y;

    if (time >= 150000 && pos_y > 50 && sfKeyboard_isKeyPressed(sfKeyZ) &&
        SHIELD.state == 'A') {
        sfClock_restart(SHIELD.c1);
        SHIELD.ps.y -= 100;
        sfSprite_setPosition(SHIELD.sp, SHIELD.ps);
    }
    if (time >= 150000 && pos_y < 750 && sfKeyboard_isKeyPressed(sfKeyS) &&
        SHIELD.state == 'A') {
        sfClock_restart(SHIELD.c1);
        SHIELD.ps.y += 100;
        sfSprite_setPosition(SHIELD.sp, SHIELD.ps);
    }
}

void anim_shield_block(void)
{
    sfInt64 time = sfClock_getElapsedTime(SHIELD.c2).microseconds;
    float bul_x = BULLET.mv_x;

    if (time >= (120000 / bul_x) && SHIELD.state == 'S') {
        sfClock_restart(SHIELD.c2);
        SHIELD.rc.left += 220;
        if (SHIELD.rc.left >= 2200) {
            SHIELD.rc.left = 0;
            BULLET.ps.x = -130;
            sfSprite_setPosition(BULLET.sp, BULLET.ps);
            SHIELD.state = 'A';
            BULLET.state = 'D';
            sfSound_play(SOUND1.sd);
        }
        sfSprite_setTextureRect(SHIELD.sp, SHIELD.rc);
    }
}
