#include "../includes/minishell.h"

void ft_prompt_cmp(char *prompt, t_env *env, char **envp, t_list *tk_l)
{
	extern char **environ;
	int i;

	tk_l = tk_l->next;
	if(tk_l){}
	i = 0;
	while(tk_l != NULL)
	{
	if (ft_strncmp("pwd", tk_l->content, 3) == 0) //compara este string con lo que está en prompt (lo que metemos)
	{
		printf("%s\n", getcwd(NULL, 0));
		tk_l = tk_l->next;
	}
	else if (ft_strncmp("exit", tk_l->content, 4) == 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (ft_strncmp("echo", tk_l->content, 4) == 0)
	{
		tk_l = tk_l->next;
		ft_echo(tk_l);
		while (tk_l != NULL && ft_strcmp(tk_l->content, "|") != 0)
			tk_l = tk_l->next;
	}
	else if (ft_strncmp("cd", tk_l->content, 2) == 0)
	{
		ft_cd(&prompt[2], env);
	}
	else if (ft_strncmp("export", tk_l->content, 6) == 0)
	{
		ft_print_export(env);
	}
	else if (ft_strncmp("unset", tk_l->content, 5) == 0)
	{
		printf("función unset\n");
	}
	else if (ft_strncmp("env", tk_l->content, 3) == 0)
		ft_print_env(env);
	else
	{
		ft_exe(prompt, env, envp);
	}
	tk_l = tk_l->next;
	}
}