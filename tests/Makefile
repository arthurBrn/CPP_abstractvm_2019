##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

#-std=c++11

NAME	=	unit_test

SRC_TEST	=	test_memory.cpp		\

SRC		=	../source/Memory.cpp	\

OBJ 	=	$(SRC:.cpp=.o)

INCLUDE	=	-I../include/

CFLAGS	=	$(INCLUDE) --coverage -O0

LDFLAGS	=	-lcriterion -lgcov

CC	=	g++

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