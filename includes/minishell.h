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
	char *nonexp;
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
# include <fcntl.h>
# include <readline/readline.h>
# include <errno.h>
# include <signal.h>
# include "../libft/libft.h"
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>

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
	int				in_fd;
	int				out_fd;
	int				ret;
	char			err;
	char			in;
	char			in2;
	char			out;
	char			out2;
	char			*input;
	char 			*nonexp;
	char			*output;
	pid_t			pid;
	struct s_cont	*list;
	struct s_proc	*next;
}               t_proc;

int		exit_status;

t_mylist	*ft_tokenizer(char *prompt, t_mylist *token_list, t_env *env);
void		ft_prompt_to_array(char *prompt, t_tokenizer *tk, t_mylist *token_list);
void		ft_make_list(t_list *head, char **token_arr, int array_size);
int			ft_prompt_cmp(t_env *env, t_cont *command, char mode);
int			ft_echo(t_cont *command);
int			ft_cd(t_env **env,  t_cont *command);
int			ft_exe(t_env *env, t_cont *command, char mode);
t_env		*ft_save_env(char **envp);
int			ft_print_export(t_env *env);
int			ft_print_env(t_env *env);
t_env		*ft_search_env(t_env *env, char *name);
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
void		ft_expander(char *token, t_mylist *tk_l, t_env *env);
char		**ft_split_env(char const *s);
int			ft_pwd();
char		**ft_make_argv(t_cont *command);
char		**ft_make_envp(t_env *env);
void		ft_command_table(t_env *env, t_mylist *tk_l);
void		ft_save_command(t_proc **proc,	t_mylist *tk_l, int total, int num);
void		ft_process_manager(t_env *env, t_proc *process);
void		ft_single_process(t_env *env, t_proc *process);
void		ft_check_redir(t_proc *process, t_mylist *temp);
int			ft_heredoc(t_proc *process);
void		ft_sig_int(int signal);
char 		*ft_dollarizer (char *content);
void		ft_redir_in(t_proc *process);
void		ft_redir_out(t_proc *process);
void		ft_exit(t_env **env);
void		ft_free_mem(char **arr);
void		ft_intermediate_redir(t_proc *process);
void		ft_last_redir(t_proc *process);
char		*ft_quote_remover(char *str);
char		*ft_get_my_env(char *key, t_env *env);
int			ft_dollar_finder(char *str);
char		*ft_key_finder(char *token);
char		*ft_final_finder(char *token, int i);
char		*ft_dequoter(char *str, int size);
int			ft_size_calc(char *str);
void		ft_init_tk(t_tokenizer *tk);
int			ft_double_pipe(t_mylist *tk_l);
int			ft_tk_delimiter(char *content);
int			ft_last_spaces(char *prompt, t_tokenizer *tk);
void		ft_flags(t_tokenizer *tk, char *prompt);
int			ft_is_dir(char *check, char mode);
int			ft_print_valid_error(char *command);


#endif