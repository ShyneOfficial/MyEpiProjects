##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	new_hashtable.c \
		ht_dump.c \
		delete_hashtable.c \
		ht_delete.c \
		ht_search.c \
		ht_insert.c \
		hash.c \
		my_strdup.c \
		flag_manager.c	\
		my_printf.c	\
		my_putchar.c	\
		my_putlong.c	\
		my_putnbr.c	\
		my_putstr.c	\

OBJ	=	$(SRC:.c=.o)

TEST_NAME	=	unit_tests

CFLAGS	=	-Wall -Wextra -Werror

TEST_SRC	=	tests/test_insert.c \

TEST_CFLAGS = --coverage -lcriterion

NAME = libhashtable.a

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rcs libhashtable.a $(OBJ)

clean:
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(TEST_NAME)
	rm -f $(NAME)

re: fclean all

test:
	$(CC) -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(TEST_CFLAGS)

tests_run: test
	./$(TEST_NAME)

show_cov: tests_run
	gcovr --exclude tests/

show_branch: tests_run
	gcovr --exclude tests/ --branches

run:
	./$(TEST_NAME)
