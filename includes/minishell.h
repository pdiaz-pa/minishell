#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_mylist {
    struct s_mylist* prev;
    char *token;
    struct s_mylist* next;
}	t_mylist;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <errno.h>
# include <signal.h>
# include "../libft/libft.h"
# include <readline/history.h>


//ft_tokenizer.c
t_mylist *ft_tokenizer(char *prompt);
char **ft_prompt_to_array(char *prompt);
void ft_make_list(t_mylist *head, char **token_arr, int array_size);
#endif