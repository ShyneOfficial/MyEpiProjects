##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## jsp
##
NAME	=	my_ls

SRC	=	complex_ls.c	\
		filter_dir.c	\
		filter_hid.c	\
		filter_rev.c	\
		filter_time.c	\
		flag_manager.c	\
		my_ls.c	\
		my_printf.c	\
		my_put_long.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putnstr.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup_va.c	\
		my_strdup.c	\
		my_strlen.c	\
		process_flags.c	\
		show_info.c	\
		show_rec.c	\
		simple_ls.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

all: libmy.a compile

libmy.a: $(OBJ)
	ar rcs libmy.a $(OBJ)

compile: clean
	gcc -o $(NAME) main.c -I. -L. -lmy $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f libmy.a

re: fclean all
