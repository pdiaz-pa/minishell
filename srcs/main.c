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

void	ft_free_tklist(t_mylist *token_list)
{
	t_mylist *temp;
	
	while(token_list)
	{
		temp = token_list->next;
		//printf("liberando\n");
		if (token_list->nonexp != NULL)
			//free(token_list->nonexp);
		if (token_list->content != NULL)
			free(token_list->content);
		free(token_list);
		token_list->next = NULL;
		token_list = temp;
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
	t_env	*env;
	t_mylist *token_list;
	env = ft_save_env(envp);
	/* ft_print_export(exp);
	ft_print_env(env);
	ft_free_env(&exp);
	ft_free_env(&env);
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
			if (prompt[0] != '\0')
				add_history(prompt); // añade la función de historia e implementa por sí mismo la funcionalidad de las flechas
			if (prompt == NULL || ft_strcmp("exit", prompt) == 0) // hay que ponerlo primero por que si strcmp detecta el NULL devuelve 0 y entra en la funicon
				ft_exit(&env);
			if (prompt[0] != '\0' && ft_only_spaces(prompt) == 1) // para evitar crasheo al no pasarle nada o solo espacios
			{
				token_list = ft_tokenizer(prompt, token_list, env); //en desarrollo. comentar esta  función si se quiere probar algo
				if(token_list->isexp != -1)
				{
					//ft_stack_printer(token_list);
					// ft_prompt_cmp(env, token_list);
				}
				exit_status = -424242;
				ft_command_table(env, token_list->next);
			}
			
			if (prompt[0] == '\0')
				exit_status = 0;
			free(prompt);
			printf ("exit: %d\n", exit_status);
			//ft_stack_printer(token_list);
			ft_free_tklist(token_list);
			//system("leaks minishell");
		}
	}
	
	return (0);
}