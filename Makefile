##
## Makefile for sudoku in /home/simon_z/rendu/Rush/sudoki-bi
## 
## Made by Morgan SIMON
## Login   <simon_z@epitech.net>
## 
## Started on  Fri Feb 26 19:33:39 2016 Morgan SIMON
## Last update Sun Feb 28 11:54:28 2016 Morgan SIMON
##

NAME	= 	bin/sudoki-bi

CC	= 	gcc

SRC	= 	src/main.c	\
		src/algo.c	\
		src/parseur.c	\
		src/pre_algo.c	\
		src/print.c	\
		src/init.c

CFLAGS	+=	-Wall -Wextra -W -O3
CFLAGS	+=	-I./include/

LDFLAGS	=

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
