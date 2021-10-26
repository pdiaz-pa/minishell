CC = gcc
CFLAGS = -Wextra -Werror -Wall
LFLAGS = -lreadline
NAME = minishell
LDFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS = -I/Users/$(USER)/.brew/opt/readline/include

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC = 	main.c

SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS) $(LFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
