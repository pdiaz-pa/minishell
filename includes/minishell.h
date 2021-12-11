#ifndef MINISHELL_H
# define MINISHELL_H

#define DOUBLEQ 34
#define SINGLEQ 39
#define SPACE 32
#define TEXT 0
#define PIPE 1
#define REDIR 2

typedef struct s_mylist{
	char *content;
	char *exp;
	int isexp;
	int tk_type;
	struct s_mylist *next;
} t_mylist;

typedef struct  s_tokenizer{
	int start;
	int sizer;
	int size;
	char ch;
	int expand;
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

typedef struct	s_cont{
	char			*content;
	struct s_cont	*next;
}				t_cont;

typedef struct  s_proc{
	struct s_proc	*prev;
	int				total;
	int				num;
	int				fd[2];
	int				ret;
	char			in;
	char			in2;
	char			out;
	char			out2;
	char			*input;
	char			*output;
	pid_t			pid;
	struct s_cont	*list;
	struct s_proc	*next;
}               t_proc;
//ft_tokenizer.c

t_mylist	*ft_tokenizer(char *prompt, t_mylist *token_list, t_env *env);
void		ft_prompt_to_array(char *prompt, t_tokenizer *tk, t_mylist *token_list);
void		ft_make_list(t_list *head, char **token_arr, int array_size);
int			ft_prompt_cmp(t_env *env, t_cont *command);
int			ft_echo(t_cont *command);
int			ft_cd(t_env **env,  t_cont *command);
void		ft_exe(t_env *env, t_cont *command);
t_env		*ft_save_env(char **envp);
int			ft_print_export(t_env *env);
int			ft_print_env(t_env *env);
t_env		*ft_search_env(t_env *env, char *name); // Devuelve la linea buscada si no la encuentra devuelve NULL
void		ft_free_env(t_env **env);
int			ft_export(t_env **env, t_cont *command);
int			ft_unset(t_env **env, t_cont *command);
void		ft_free_all(t_list *token_list, char **token_arr, t_tokenizer *tk);
void		ft_free_list(t_list *token_list);
void		ft_stack_printer(t_mylist *stack);
void		ft_mylstadd_back(t_mylist **lst, t_mylist *new);
void		ft_save_env_line(t_env **env, char *envp);
t_mylist	*ft_mylstnew(void *content, int isexp);
t_mylist	*ft_mylstlast(t_mylist *lst);
t_mylist	*ft_init_t_stack(void);
void		ft_expander(char *token, char *savedtk, t_mylist *tk_l, t_env *env);
char		**ft_split_env(char const *s);
int			ft_pwd();
char		**ft_make_argv(t_cont *command);
char		**ft_make_envp(t_env *env);
void		ft_command_table(t_env *env, t_mylist *tk_l);
void		ft_save_command(t_proc **proc,	t_mylist *tk_l, int total, int num);

#endif