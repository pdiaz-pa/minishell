# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <errno.h>

//compilar con gcc -lreadline

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	main()
{
	/*Antes de todo, hay que hacer que:
		-Control + C no salga del programa
		-Control + D salga del programa
	igual que en bash */
	while (1)
	{
		int again;
		char *prompt;

		again = 1;
		while (again)
		{
			again = 0;
			prompt = readline("my_minishell$ ");
			if (ft_strcmp("pwd", prompt) == 0) //compara este string con lo que está en prompt (lo que metemos)
				write(1, "la ruta en la que nos encontramos\n", 35);
			if (ft_strcmp("exit", prompt) == 0)
			{
				write(1, "exit\n", 5);
				exit(1);
			}
			free(prompt);
		}
	}
	return (0);
}