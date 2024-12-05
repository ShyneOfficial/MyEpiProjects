/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** initialize_sprites
*/
#include "my.h"

void initialize_ship(void)
{
    SHIP.tx = sfTexture_createFromFile("ship_sheet.png", NULL);
    SHIP.sp = sfSprite_create();
    SHIP.rc = (sfIntRect){0, 0, 240, 240};
    SHIP.ps = (sfVector2f){-300, 41};
    SHIP.c1 = sfClock_create();
    SHIP.c2 = sfClock_create();
    SHIP.mv_x = 1;
    SHIP.mv_y = 0;
    SHIP.state = 'A';
    sfSprite_setTexture(SHIP.sp, SHIP.tx, sfTrue);
    sfSprite_setTextureRect(SHIP.sp, SHIP.rc);
    sfSprite_setPosition(SHIP.sp, SHIP.ps);
}

void initialize_bullet(void)
{
    BULLET.tx = sfTexture_createFromFile("bullet_sheet.png", NULL);
    BULLET.sp = sfSprite_create();
    BULLET.rc = (sfIntRect){0, 0, 80, 40};
    BULLET.ps = (sfVector2f){-130, 0};
    BULLET.c1 = sfClock_create();
    BULLET.c2 = sfClock_create();
    BULLET.mv_x = 4;
    BULLET.mv_y = 0;
    BULLET.state = 'D';
    sfSprite_setTexture(BULLET.sp, BULLET.tx, sfTrue);
    sfSprite_setTextureRect(BULLET.sp, BULLET.rc);
    sfSprite_setPosition(BULLET.sp, BULLET.ps);
}

void initialize_background1(void)
{
    BG1.tx = sfTexture_createFromFile("animated_background.png", NULL);
    BG1.sp = sfSprite_create();
    BG1.rc = (sfIntRect){0, 0, 1821, 1080};
    BG1.ps = (sfVector2f){0, 0};
    BG1.c1 = sfClock_create();
    BG1.c2 = sfClock_create();
    BG1.state = 'D';
    sfSprite_setTexture(BG1.sp, BG1.tx, sfTrue);
    sfSprite_setTextureRect(BG1.sp, BG1.rc);
    sfSprite_setPosition(BG1.sp, BG1.ps);
}

void initialize_shield(void)
{
    SHIELD.tx = sfTexture_createFromFile("shield_sheet.png", NULL);
    SHIELD.sp = sfSprite_create();
    SHIELD.rc = (sfIntRect){0, 0, 220, 220};
    SHIELD.ps = (sfVector2f){1600, 350};
    SHIELD.c1 = sfClock_create();
    SHIELD.c2 = sfClock_create();
    SHIELD.mv_x = 100;
    SHIELD.mv_y = 0;
    SHIELD.state = 'A';
    sfSprite_setTexture(SHIELD.sp, SHIELD.tx, sfTrue);
    sfSprite_setTextureRect(SHIELD.sp, SHIELD.rc);
    sfSprite_setPosition(SHIELD.sp, SHIELD.ps);
}

void initialize_hp(void)
{
    HPBAR.tx = sfTexture_createFromFile("hpBar_sheet.png", NULL);
    HPBAR.sp = sfSprite_create();
    HPBAR.rc = (sfIntRect){1200, 0, 300, 70};
    HPBAR.ps = (sfVector2f){0, 0};
    HPBAR.c1 = sfClock_create();
    HPBAR.c2 = sfClock_create();
    HPBAR.mv_x = 4;
    HPBAR.mv_y = 0;
    HPBAR.state = 'A';
    sfSprite_setTexture(HPBAR.sp, HPBAR.tx, sfTrue);
    sfSprite_setTextureRect(HPBAR.sp, HPBAR.rc);
    sfSprite_setPosition(HPBAR.sp, HPBAR.ps);
}
