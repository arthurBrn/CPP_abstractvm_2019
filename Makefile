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

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS +=	-Wall

CPPFLAGS = -I./include/

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
