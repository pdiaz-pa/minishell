#include "../includes/minishell.h"

int ft_only_spaces(char *prompt)
{
	int count;

	count = 0;

	while (prompt[count] != '\0')
	{
		if(prompt[count] != ' ' && prompt[count] != '\0')
			return(1);
		count++;
	}
	return(0);
}

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

int	main(int argc, char **argv, char **envp)
{
	/*Antes de todo, hay que hacer que:
		-Control + C no salga del programa
		-Control + D salga del programa (cuando prompt == NULL)
	igual que en bash */

	int again;
	char *prompt;
	(void)argc;
	(void)argv;
	t_env	*exp;
	t_env	*env;

	exp = save_exp(envp);
	env = save_env(envp);
	/* ft_print_export(exp);
	ft_print_env(env);
	free_env(&exp);
	free_env(&env);
 */

	while (1)
	{
		signal(SIGQUIT, SIG_IGN); // anula el funcionamiento de ctrl + "\"
		signal(SIGINT, &ft_sig_int); // cambia el funcionamiento de ctrl + "C"
		again = 1;
		while (again)
		{
			again = 0;
			prompt = readline("minishell$ ");
			add_history(prompt); // añade la función de historia e implementa por sí mismo la funcionalidad de las flechas
			if (prompt == NULL || ft_strcmp("exit", prompt) == 0) // hay que ponerlo primero por que si strcmp detecta el NULL devuelve 0 y entra en la funicon
				exit(1);
			ft_prompt_cmp(prompt, env, exp, envp);
			if (prompt[0] != '\0' && ft_only_spaces(prompt) == 1) // para evitar crasheo al no pasarle nada o solo espacios
				ft_tokenizer(prompt); //en desarrollo. comentar esta  función si se quiere probar algo
			free(prompt);
		}
	}
	return (0);
}