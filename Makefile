##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	abstractVM

CC	=	g++

SRCS	=	./source/main.cpp	\
		./source/Chipset.cpp	\
		./source/AbstractVmException.cpp	\
		./source/CPU.cpp	\
		./source/Memory.cpp	\
		./source/Input.cpp	\
		./source/Output.cpp	\
		./source/Factory.cpp	\
		./source/Operand.cpp	\
		./source/IOperand.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

TEST_DIR	=	tests/

CFLAGS +=	-W -Wall -Wpedantic -Wextra -Wshadow -Wstrict-overflow=5 -Wmissing-declarations -Wundef 

CPPFLAGS = -I./include/ -std=c++11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(TEST_DIR) fclean

tests_run:
	$(MAKE) -C $(TEST_DIR)
	./$(TEST_DIR)unit_test

coverage:
	gcovr --exclude tests --branch

re: fclean all
