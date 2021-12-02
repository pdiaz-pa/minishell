#include "../includes/minishell.h"

void ft_prompt_cmp(t_env *env, t_mylist *tk_l)
{
	/* t_mylist *temp;

	temp = tk_l;
	while (temp != NULL)
	{
		printf("line %s, %d, %p\n", temp->content, temp->tk_type, temp->next);
		temp = temp->next;
	} */
	tk_l = tk_l->next;
	// while(tk_l != NULL)
	// {
	if (ft_strcmp("pwd", tk_l->content) == 0) //compara este string con lo que está en prompt (lo que metemos)
	{
		ft_pwd();
		tk_l = tk_l->next;
	}
	else if (ft_strcmp("exit", tk_l->content) == 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (ft_strcmp("echo", tk_l->content) == 0)
	{
		tk_l = tk_l->next;
		printf("echo send%p\n", tk_l);
		ft_echo(tk_l);
		while (tk_l != NULL && tk_l->next != NULL && tk_l->next->tk_type == 0)
			tk_l = tk_l->next;
	}
	else if (ft_strcmp("cd", tk_l->content) == 0)
	{
		ft_cd(&env, tk_l->next);
	}
	else if (ft_strcmp("export", tk_l->content) == 0)
	{
		ft_export(&env, tk_l->next);
	}
	else if (ft_strcmp("unset", tk_l->content) == 0)
	{
		ft_unset(&env, tk_l->next);
	}
	else if (ft_strcmp("env", tk_l->content) == 0)
		ft_print_env(env);
	else
	{
		ft_exe(env, tk_l);
	}
	// if (tk_l != NULL)
		// tk_l = tk_l->next;
	// }
}