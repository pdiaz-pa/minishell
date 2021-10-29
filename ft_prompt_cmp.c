#include "../includes/minishell.h"

void ft_prompt_cmp(char *prompt)
{
	extern char **environ;
	int i;

	i = 0;
	if (ft_strcmp("pwd", prompt) == 0) //compara este string con lo que está en prompt (lo que metemos)
				printf("%s\n", getcwd(NULL, 0));
	else if (ft_strcmp("exit", prompt) == 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (ft_strcmp("echo", prompt) == 0)
	{
		printf("función echo\n");
	}
	else if (ft_strcmp("cd", prompt) == 0)
	{
		printf("función cd\n");
	}
	else if (ft_strcmp("export", prompt) == 0)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			printf("%s", "declare -x ");
			printf("%s\n", environ[i]);
			i++;
		}
	}
	else if (ft_strcmp("unset", prompt) == 0)
	{
		printf("función unset\n");
	}
	else if (ft_strcmp("env", prompt) == 0)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
	}
	else if (ft_strcmp("/", prompt) == 0)
	{
		printf("función barra\n");
	}
}