# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <errno.h>

//compilar con gcc -l readline

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

void ignore_signal_for_shell()
{
	void   (*SIGINT_handler)(int);
	
	// ignore "Ctrl-C"
    SIGINT_handler = signal(SIGINT, SIG_IGN);
	// ignore "Ctrl-Z"
    signal(SIGTSTP, SIG_IGN);
	// ignore "Ctrl-\"
    signal(SIGQUIT, SIG_IGN);
}
void	sig_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
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
	ignore_signal_for_shell();
	while (1)
	{

		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &sig_int);
		again = 1;
		while (again)
		{
			again = 0;
			prompt = readline("my_minishell$ ");
			if (prompt == NULL) // hay que ponerlo primero por que si strcmp detecta el NULL devuelve 0 y entra en la funicon
				exit(1);
			else if (ft_strcmp("pwd", prompt) == 0) //compara este string con lo que está en prompt (lo que metemos)
				write(1, "la ruta en la que nos encontramos\n", 35);
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