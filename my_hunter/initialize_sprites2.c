/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** initialize_sprites2
*/
#include "my.h"

void initialize_crosshair1(void)
{
    CROSSHAIR.tx = sfTexture_createFromFile("crosshair1.png", NULL);
    CROSSHAIR.sp = sfSprite_create();
    CROSSHAIR.rc = (sfIntRect){0, 0, 100, 100};
    CROSSHAIR.ps = (sfVector2f){0, 0};
    CROSSHAIR.c1 = sfClock_create();
    CROSSHAIR.c2 = sfClock_create();
    CROSSHAIR.mv_x = 1;
    CROSSHAIR.mv_y = 0;
    CROSSHAIR.state = 'A';
    sfSprite_setTexture(CROSSHAIR.sp, CROSSHAIR.tx, sfTrue);
    sfSprite_setTextureRect(CROSSHAIR.sp, CROSSHAIR.rc);
    sfSprite_setPosition(CROSSHAIR.sp, CROSSHAIR.ps);
    sfSprite_setOrigin(CROSSHAIR.sp, (sfVector2f){50, 50});
}

void initialize_background2(void)
{
    BG2.tx = sfTexture_createFromFile("background.png", NULL);
    BG2.sp = sfSprite_create();
    BG2.rc = (sfIntRect){0, 0, 1821, 1024};
    BG2.ps = (sfVector2f){0, 0};
    BG2.c1 = sfClock_create();
    BG2.c2 = sfClock_create();
    BG2.state = 'A';
    sfSprite_setTexture(BG2.sp, BG2.tx, sfTrue);
    sfSprite_setTextureRect(BG2.sp, BG2.rc);
    sfSprite_setPosition(BG2.sp, BG2.ps);
}

void initialize_cursor(void)
{
    CURSOR.tx = sfTexture_createFromFile("cursor.png", NULL);
    CURSOR.sp = sfSprite_create();
    CURSOR.rc = (sfIntRect){0, 0, 30, 30};
    CURSOR.ps = (sfVector2f){0, 0};
    CURSOR.c1 = sfClock_create();
    CURSOR.c2 = sfClock_create();
    CURSOR.state = 'A';
    sfSprite_setTexture(CURSOR.sp, CURSOR.tx, sfTrue);
    sfSprite_setTextureRect(CURSOR.sp, CURSOR.rc);
    sfSprite_setPosition(CURSOR.sp, CURSOR.ps);
}
