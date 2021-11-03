#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_mylist {
    struct s_mylist* prev;
    char *token;
    struct s_mylist* next;
}	t_mylist;

typedef struct  s_tokenizer{
	int start;
	int sizer;
	int size;
}	t_tokenizer;

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
char **ft_prompt_to_array(char *prompt, t_tokenizer *tk);
void ft_make_list(t_mylist *head, char **token_arr, int array_size);
void ft_prompt_cmp(char *prompt, char **envp);
void	ft_echo(char **argv);
void	ft_cd(char *argv);
void	ft_exe(char *path, char **envp);

#endif