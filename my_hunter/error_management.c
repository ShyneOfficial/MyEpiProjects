/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** error_management
*/
#include "my.h"

int error_management_png(void)
{
    if (open("animated_background.png", O_RDONLY) == -1)
        return 1;
    if (open("bullet_sheet.png", O_RDONLY) == -1)
        return 1;
    if (open("hpBar_sheet.png", O_RDONLY) == -1)
        return 1;
    if (open("shield_sheet.png", O_RDONLY) == -1)
        return 1;
    if (open("ship_sheet.png", O_RDONLY) == -1)
        return 1;
    if (open("crosshair1.png", O_RDONLY) == -1)
        return 1;
    if (open("background.png", O_RDONLY) == -1)
        return 1;
    if (open("cursor.png", O_RDONLY) == -1)
        return 1;
    return 0;
}

int error_management_mp3(void)
{
    if (open("bulletDestSound.mp3", O_RDONLY) == -1)
        return 1;
    if (open("gameMusic.ogg", O_RDONLY) == -1)
        return 1;
    if (open("menuMusic.ogg", O_RDONLY) == -1)
        return 1;
    if (open("hpLost.mp3", O_RDONLY) == -1)
        return 1;
    if (open("shipDestSound.mp3", O_RDONLY) == -1)
        return 1;
    return 0;
}

int error_management_sp1(sfRenderWindow *win)
{
    if (!win)
        return 1;
    if (!SHIP.tx || !SHIP.sp || !SHIP.c1 || !SHIP.c2)
        return 1;
    if (!BULLET.tx || !BULLET.sp || !BULLET.c1 || !BULLET.c2)
        return 1;
    if (!BG1.tx || !BG1.sp || !BG1.c1 || !BG1.c2)
        return 1;
    if (!SHIELD.tx || !SHIELD.sp || !SHIELD.c1 || !SHIELD.c2)
        return 1;
    if (!HPBAR.tx || !HPBAR.sp || !HPBAR.c1 || !HPBAR.c2)
        return 1;
    return 0;
}

int error_management_sp2(void)
{
    if (!CROSSHAIR.tx || !CROSSHAIR.sp || !CROSSHAIR.c1 || !CROSSHAIR.c2)
        return 1;
    if (!BG2.tx || !BG2.sp || !BG2.c1 || !BG2.c2)
        return 1;
    if (!CURSOR.tx || !CURSOR.sp || !CURSOR.c1 || !CURSOR.c2)
        return 1;
    return 0;
}

int error_management2(void)
{
    if (!SOUND0.sd || !SOUND0.sd)
        return 1;
    if (!SOUND1.sd || !SOUND1.sd)
        return 1;
    if (!SOUND2.sd || !SOUND2.sd)
        return 1;
    if (!MUSIC0.mc || !MUSIC1.mc)
        return 1;
    if (!TEXT0.text || !TEXT1.text || !TEXT2.text || !TEXT3.text)
        return 1;
    if (!TEXT4.text || !TEXT5.text)
        return 1;
    return 0;
}
