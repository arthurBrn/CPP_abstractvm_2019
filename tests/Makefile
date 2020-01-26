##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

#-std=c++11

NAME	=	unit_test

SRC_TEST	=	test_memory.cpp		\
			test_cpu_regular.cpp	\
			test_factory.cpp	\

SRC		=	../source/Memory.cpp	\
			../source/AbstractVmException.cpp	\
			../source/IOperand.cpp	\
			../source/Output.cpp	\
			../source/Factory.cpp	\
			../source/Operand.cpp	\
			../source/CPU.cpp	\

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
