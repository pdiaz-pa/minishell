#include "../includes/minishell.h"

void	ft_sig_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line(); // indica a las siguientes funciones que estamos en la siguiente línea
		rl_replace_line("", 1); // reemplaza la línea con lo que le indiques
		rl_redisplay(); // muestra de nuevo lo que tenemos en prompt
	}
}

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
}

int	main()
{
	/*Antes de todo, hay que hacer que:
		-Control + C no salga del programa
		-Control + D salga del programa (cuando prompt == NULL)
	igual que en bash */

	int again;
	char *prompt;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN); // anula el funcionamiento de ctrl + "\"
		signal(SIGINT, &ft_sig_int); // cambia el funcionamiento de ctrl + "C"
		again = 1;
		while (again)
		{
			again = 0;
			prompt = readline("my_minishell$ ");
			add_history(prompt); // añade la función de historia e implementa por sí mismo la funcionalidad de las flechas
			if (prompt == NULL) // hay que ponerlo primero por que si strcmp detecta el NULL devuelve 0 y entra en la funicon
				exit(1);
			ft_prompt_cmp(prompt);
			
			free(prompt);
		}
	}
	return (0);
}