#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0); //	Al devolver 0 se puede confundir el fallo con un string sin cambios
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sig_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line(); // indica a las siguientes funciones que estamos en la siguiente línea
		// rl_replace_line("", 1); // reemplaza la línea con lo que le indiques
		rl_redisplay(); // muestra de nuevo lo que tenemos en prompt
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
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &ft_sig_int);
		again = 1;
		while (again)
		{
			again = 0;
			prompt = readline("my_minishell$ ");
			if (prompt == NULL) // hay que ponerlo primero por que si strcmp detecta el NULL devuelve 0 y entra en la funicon
				exit(1);
			else if (ft_strcmp("pwd", prompt) == 0) //compara este string con lo que está en prompt (lo que metemos)
				printf("%s\n", getcwd(NULL, 0));
			else if (ft_strcmp("exit", prompt) == 0)
			{
				write(1, "exit\n", 5);
				exit(1);
			}
			free(prompt);
		}
	}
	return (0);
}