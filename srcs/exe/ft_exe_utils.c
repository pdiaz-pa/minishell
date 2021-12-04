/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:47:17 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/04 15:38:56 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_make_argv(t_cont *command)
{
	char		**argv;
	t_cont	*temp;
	int			i;

	temp = command;
	i = 1;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	argv = (char **)malloc(sizeof(char *) * i);
	temp = command;
	i = 0;
	while (temp != NULL)
	{
		argv[i] = temp->content;
		i++;
		temp = temp->next;
	}
	argv[i] = NULL;
	return (argv);
}

char	**ft_make_envp(t_env *env)
{
	char		**envp;
	t_env		*temp;
	char		*temp2;
	int			i;

	temp = env;
	i = 1;
	while (temp != NULL)
	{
		if (temp->line[1])
			i++;
		temp = temp->next;
	}
	envp = (char **)malloc(sizeof(char *) * i);
	temp = env;
	i = 0;
	while (temp != NULL)
	{
		if (temp->line[1])
		{
			temp2 = ft_strjoin(temp->line[0], "=");
			envp[i] = ft_strjoin(temp2, temp->line[1]);
			i++;
		}
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}
