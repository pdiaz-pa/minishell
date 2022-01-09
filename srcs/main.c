/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:43:06 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/09 06:33:18 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	ft_ctrl_d(struct termios termattr, t_env *env)
{
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\033[11C", 1);
	ft_putstr_fd("exit\n", 1);
	reset_termattr(&termattr);
	ft_exit(&env, NULL, 'b');
}

void	ft_free_prompt(char *prompt)
{
	free(prompt);
	prompt = NULL;
}

int	ft_main_loop(int again, char *prompt, t_env *env, t_mylist *token_list)
{
	struct termios	termattr;

	backup_termattr(&termattr);
	turnoff_echoctl_termattr();
	ft_signal_handle();
	again = 0;
	prompt = readline("minishell$ ");
	if (prompt == NULL)
		ft_ctrl_d(termattr, env);
	if (prompt != NULL && prompt[0] != '\0')
		add_history(prompt);
	if (prompt[0] != '\0' && ft_only_spaces(prompt) == 1)
	{
		token_list = ft_tokenizer(prompt, token_list, env);
		if (token_list->isexp != -1)
			ft_command_table(env, token_list->next);
		else
			g_exit_status = 1;
	}
	if (prompt[0] == '\0')
		g_exit_status = 0;
	if (prompt[0] != '\0' && ft_only_spaces(prompt) == 1)
		ft_free_tklist(token_list);
	ft_free_prompt(prompt);
	return (again);
}

int	main(int argc, char **argv, char **envp)
{
	int			again;
	char		*prompt;
	t_env		*env;
	t_mylist	*token_list;	

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
