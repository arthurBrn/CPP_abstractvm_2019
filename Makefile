##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	abstractVM

CC	=	g++

SRCS	=	./source/main.cpp		\
		./source/Chipset.cpp	\
		./source/AbstractVmException.cpp	\
		./source/CPU.cpp	\
		./source/Memory.cpp	\
		./source/Input.cpp	\
		./source/Output.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS +=	-Wall

CPPFLAGS = -I./include/ -std=c++11

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
