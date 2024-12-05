/*
** EPITECH PROJECT, 2024
** MyHunter
** File description:
** manage_text
*/
#include "my.h"

void set_text(sfText *txt, sfVector2f pos, sfVector2f scale)
{
    sfText_setPosition(txt, pos);
    sfText_setScale(txt, scale);
}

void initialize_text(void)
{
    for (int i = 0; i != 6; i++) {
        GAME->text[i].text = sfText_create();
        sfText_setFont(GAME->text[i].text, sfFont_createFromFile("font.ttf"));
    }
    set_text(TEXT0.text, (sfVector2f){20, 870}, (sfVector2f){4, 4});
    set_text(TEXT1.text, (sfVector2f){230, 400}, (sfVector2f){0.7, 0.7});
    sfText_setString(TEXT1.text, "Made by Iyad Hossen");
    set_text(TEXT2.text, (sfVector2f){100, 300}, (sfVector2f){3, 3});
    sfText_setString(TEXT2.text, "SpaceHunt");
    set_text(TEXT3.text, (sfVector2f){150, 600}, (sfVector2f){2, 2});
    sfText_setString(TEXT3.text, "Press Space");
    set_text(TEXT4.text, (sfVector2f){210, 700}, (sfVector2f){1.6, 1.6});
    sfText_setString(TEXT4.text, "You lost :/");
    set_text(TEXT5.text, (sfVector2f){10, 970}, (sfVector2f){1, 1});
    sfText_setString(TEXT5.text, "Last Score:");
}

void destroy_text(void)
{
    for (int i = 0; i != 4; i++)
        sfText_destroy(GAME->text[i].text);
}
