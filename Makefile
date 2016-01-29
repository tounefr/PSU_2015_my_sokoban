##
## Makefile for  in /home/thomas/Documents/epitech
## 
## Made by thomas
## Login   <thomas@epitech.net>
## 
## Started on  Mon Jan  4 09:58:11 2016 thomas
## Last update Fri Jan 15 09:39:08 2016 thomas
##


NAME = my_sokoban

SRCS =	main.c \
	get_next_line/get_next_line.c \
	util.c \
	linked_lists.c \
	map_parsing.c \
	map_parsing2.c \
	movement.c \
	game.c \
	map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -l my -L ./my -I ./my -lncurses -Wall

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
