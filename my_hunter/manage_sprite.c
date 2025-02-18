/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** initialize_sprite
*/
#include "my.h"

void draw_game_sprites(sfRenderWindow *win, char *score_text)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, BG1.sp, NULL);
    sfRenderWindow_drawSprite(win, SHIP.sp, NULL);
    if (SHIELD.state != '?')
        sfRenderWindow_drawSprite(win, SHIELD.sp, NULL);
    if (BULLET.state == 'A')
        sfRenderWindow_drawSprite(win, BULLET.sp, NULL);
    sfRenderWindow_drawSprite(win, HPBAR.sp, NULL);
    sfText_setString(TEXT0.text, my_nbr_to_str(score_text, HPBAR.mv_y));
    sfRenderWindow_drawText(win, TEXT0.text, NULL);
    sfRenderWindow_drawSprite(win, CROSSHAIR.sp, NULL);
}

void draw_menu_sprites(sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, BG2.sp, NULL);
    sfRenderWindow_drawText(win, TEXT1.text, NULL);
    sfRenderWindow_drawText(win, TEXT2.text, NULL);
    sfRenderWindow_drawText(win, TEXT3.text, NULL);
    if (HPBAR.state == 'D') {
        sfRenderWindow_drawText(win, TEXT4.text, NULL);
        sfRenderWindow_drawText(win, TEXT5.text, NULL);
        sfRenderWindow_drawText(win, TEXT0.text, NULL);
    }
    sfRenderWindow_drawSprite(win, CURSOR.sp, NULL);
}

void destroy_sprites(void)
{
    for (int i = 0; i != 8; i++) {
        sfTexture_destroy(GAME->sprite[i].tx);
        sfSprite_destroy(GAME->sprite[i].sp);
        sfClock_destroy(GAME->sprite[i].c1);
        sfClock_destroy(GAME->sprite[i].c2);
    }
}
