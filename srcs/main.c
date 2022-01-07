/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:43:06 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/07 07:38:46 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_only_spaces(char *prompt)
{
	int	count;

	count = 0;
	while (prompt[count] != '\0')
	{
		if (prompt[count] != ' ' && prompt[count] != '\0')
			return (1);
		count++;
	}
	return (0);
}

void	ft_sig_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		exit_status = 1;
	}
}

void	ft_free_tklist(t_mylist *token_list)
{
	t_mylist	*temp;

	while (token_list)
	{
		temp = token_list->next;
		free(token_list->nonexp);
		free(token_list->content);
		token_list->content = NULL;
		token_list->next = NULL;
		free(token_list);
		token_list = temp;
	}
}

int	ft_main_loop(int again, char *prompt, t_env *env, t_mylist *token_list)
{
	struct termios termattr;

	backup_termattr(&termattr);
	turnoff_echoctl_termattr();
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ft_sig_int);
	again = 0;
	prompt = readline("minishell$ ");
	if (prompt == NULL)
	{
		rl_redisplay();
		reset_termattr(&termattr);
		ft_exit(&env, NULL, 'a');
	}
	if (prompt != NULL && prompt[0] != '\0')
		add_history(prompt);
	if (prompt[0] != '\0' && ft_only_spaces(prompt) == 1)
	{
		token_list = ft_tokenizer(prompt, token_list, env);
		if (token_list->isexp != -1)
			ft_command_table(env, token_list->next);
		else
			exit_status = 1;
	}
	if (prompt[0] == '\0')
		exit_status = 0;
	if (prompt[0] != '\0' && ft_only_spaces(prompt) == 1)
		ft_free_tklist(token_list);
	free(prompt);
	prompt = NULL;
	return (again);
}

int	main(int argc, char **argv, char **envp)
{
	int			again;
	char		*prompt;
	t_env		*env;
	t_mylist	*token_list;	
	//rl_catch_signals = 0;
	token_list = NULL;
	prompt = NULL;
	(void)argc;
	(void)argv;
	env = ft_save_env(envp);
	while (1)
	{
		again = 1;
		while (again)
			again = ft_main_loop(again, prompt, env, token_list);
	}
	return (0);
}
