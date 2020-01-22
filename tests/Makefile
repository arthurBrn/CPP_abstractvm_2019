##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

NAME	=	unit_test

SRC_TEST	=	test_run_board.c			\



SRC		=	../src/run_start.c					\

OBJ 	=	$(SRC:.c=.o)

INCLUDE	=	-I../include

CFLAGS	=	$(INCLUDE) --coverage -O0

LDFLAGS	=	-lcriterion -lgcov

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(SRC_TEST) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(wildcard *.gc*)
		$(RM) ./../src/*.gcno
		$(RM) ./../src/*.gcda

re: fclean all

.PHONY:	all clean fclean re
