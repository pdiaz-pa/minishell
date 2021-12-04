#include "../includes/minishell.h"

void ft_prompt_cmp(t_env *env, t_cont *command)
{
	/* t_mylist *temp;

	temp = tk_l;
	while (temp != NULL)
	{
		printf("line %s, %d, %p\n", temp->content, temp->tk_type, temp->next);
		temp = temp->next;
	} */
	// while(tk_l != NULL)
	// {
	if (ft_strcmp("pwd", command->content) == 0) //compara este string con lo que está en prompt (lo que metemos)
	{
		ft_pwd();
	}
	else if (ft_strcmp("exit", command->content) == 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (ft_strcmp("echo", command->content) == 0)
	{
		ft_echo(command->next);
	}
	else if (ft_strcmp("cd", command->content) == 0)
	{
		ft_cd(&env, command->next);
	}
	else if (ft_strcmp("export", command->content) == 0)
	{
		ft_export(&env, command->next);
	}
	else if (ft_strcmp("unset", command->content) == 0)
	{
		ft_unset(&env, command->next);
	}
	else if (ft_strcmp("env", command->content) == 0)
		ft_print_env(env);
	else
	{
		ft_exe(env, command);
	}
	// if (tk_l != NULL)
		// tk_l = tk_l->next;
	// }
}