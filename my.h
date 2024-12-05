/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** jsp
*/
#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Clock.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <math.h>
    #include <fcntl.h>
    #include "struct.h"
    #include "define.h"

int my_strcmp(char const *s1, char const *s2);
int my_nbrlen(int nb);
char *my_nbr_to_str(char *str, int nb);
void my_putchar(char c);
void my_putstr(char *str);
void loop_game(sfRenderWindow *win, char *score_text);
void loop_menu(sfRenderWindow *win);
void init_game(sfRenderWindow *win);
void initialize_game(sfRenderWindow *win);
void initialize_menu(void);
void initialize_ship(void);
void initialize_bullet(void);
void initialize_background1(void);
void initialize_shield(void);
void initialize_hp(void);
void initialize_crosshair1(void);
void initialize_ship_dest_sound(void);
void initialize_bullet_dest_sound(void);
void initialize_hp_lost(void);
void initialize_background2(void);
void initialize_cursor(void);
void initialize_musics(void);
void initialize_text(void);
void destroy_text(void);
int error_management_png(void);
int error_management_mp3(void);
int error_management_sp1(sfRenderWindow *win);
int error_management_sp2(void);
int error_management2(void);
int gameloop(sfVideoMode mode, char *score_text, sfEvent evt);
void update_hp(void);
void anim_bg(void);
void move_ship(void);
void anim_ship_move(void);
void anim_ship_destroy(void);
void check_shoot(sfVector2i mouse);
void launch_bullet(void);
void move_bullet(void);
void anim_bullet_move(void);
void check_collide(void);
void move_shield(void);
void anim_shield_block(void);
void update_crosshair1(sfRenderWindow *win);
void update_cursor(sfRenderWindow *win);
void anim_text(void);
void draw_game_sprites(sfRenderWindow *win, char *score_text);
void draw_menu_sprites(sfRenderWindow *win);
void destroy_sprites(void);
void destroy_sounds(void);
void destroy_text(void);
void fini_game(sfRenderWindow *win);
game_t *game(void);

#endif
