CC = gcc
CFLAGS = -Wextra -Werror -Wall
LFLAGS = -lreadline
NAME = minishell
LDFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS = -I/Users/$(USER)/.brew/opt/readline/include
MLIBFT = make -C ./libft/
CLIBFT = cp libft/libft.a .
LIBFT = libft.a


DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC = 	main.c \
		ft_tokenizer.c

SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MLIBFT)
	$(CLIBFT)
	$(CC) -o $(NAME) -I $(DIR_H) $(LIBFT) $(OBJS) $(CFLAGS) $(LFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(LIBFT)
	$(MLIBFT) fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
