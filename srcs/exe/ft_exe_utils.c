/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:47:17 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/29 11:22:55 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_make_argv(t_mylist *tk_l)
{
	char		**argv;
	t_mylist	*temp;
	int			i;

	temp = tk_l;
	i = 1;
	while (temp != NULL && temp->tk_type == 0)
	{
		i++;
		temp = temp->next;
	}
	argv = (char **)malloc(sizeof(char *) * i);
	temp = tk_l;
	i = 0;
	while (temp != NULL && temp->tk_type == 0)
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
