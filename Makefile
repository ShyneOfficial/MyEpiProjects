##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## jsp
##
NAME	=	my_hunter

SRC	=	my_strcmp.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_nbr_to_str.c	\
		my_nbrlen.c	\

OBJ	=	$(SRC:.c=.o)

FILE	=	main.c	\
			gameloop.c	\
			init_game.c	\
			manage_game_loop.c	\
			manage_game_graphics.c	\
			initialize_sprites.c	\
			initialize_sprites2.c	\
			error_management.c	\
			manage_sprite.c	\
			manage_ship.c	\
			manage_bullet.c	\
			manage_shield.c	\
			manage_sound.c	\
			manage_music.c	\
			manage_text.c	\

FLAGS	=	-Werror -Wall -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all: libmy.a compile

libmy.a: $(OBJ)
	ar rcs libmy.a $(OBJ)

compile:
	gcc -o $(NAME) $(FILE) $(CSFML) $(FLAGS) -L. -lmy -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	./$(NAME)
