CC = gcc
CFLAGS = -Wextra -Werror -Wall -g
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
		ft_tokenizer.c \
		ft_prompt_cmp.c \
		builtins/ft_echo.c \
		builtins/ft_cd.c \
		builtins/ft_export.c \
		builtins/ft_print_export.c \
		builtins/ft_env_utils.c \
		builtins/ft_env.c \
		builtins/ft_unset.c \
		builtins/ft_pwd.c \
		builtins/ft_exit.c \
		exe/ft_exe.c \
		exe/ft_exe_utils.c \
		ft_list_utils.c \
		ft_expander.c \
		ft_command_table.c \
		ft_save_command.c \
		ft_save_command_utils.c \
		ft_process_manager.c \
		ft_process_manager_utils.c \
		ft_heredoc.c	\

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
