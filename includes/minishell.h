#ifndef MINISHELL_H
# define MINISHELL_H
/*
typedef struct s_list {
    char *token;
    struct s_list* next;
}	t_list;
*/
typedef struct  s_tokenizer{
	int start;
	int sizer;
	int size;
    char ch;
    int single_flag;
    int double_flag;
    char **arr;
}	t_tokenizer;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <errno.h>
# include <signal.h>
# include "../libft/libft.h"
# include <readline/history.h>

typedef struct  s_env{
    char			**line;
    struct s_env	*next;
}	            t_env;

//ft_tokenizer.c
t_list *ft_tokenizer(char *prompt);
void    ft_prompt_to_array(char *prompt, t_tokenizer *tk, t_list *token_list);
void ft_make_list(t_list *head, char **token_arr, int array_size);
void ft_prompt_cmp(char *prompt, t_env *env, t_env *exp, char **envp);
void	ft_echo(char **argv);
void	ft_cd(char *argv, t_env *env);
void	ft_exe(char *path, t_env *env, char **envp);
t_env	*save_exp(char **envp);
t_env	*save_env(char **envp);
int		ft_print_export(t_env *env);
int	    ft_print_env(t_env *env);
void	save_line(t_env **env, char *envp); //Guarda una linea en env ordenada
t_env   *search_env(t_env *env, char *name); // Devuelve la linea buscada si no la encuentra devuelve NULL
void	free_env(t_env **env);

void	ft_free_all(t_list *token_list, char **token_arr, t_tokenizer *tk);
void	ft_free_list(t_list *token_list);
void ft_stack_printer(t_list *stack);
t_list *ft_init_t_stack(void);


#endif