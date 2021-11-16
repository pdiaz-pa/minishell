/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/16 15:05:11 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	old_pwd(t_env *env);

int	ft_export(t_env exp, t_env env, char *str)
{
	
}

int	ft_print_export(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL)
	{
		printf("declare -x ");
		printf("%s", temp->line[0]);
		if (temp->line[1])
		{
			printf("=\"");
			printf("%s", temp->line[1]);
			printf("\"\n");
		}
		else
			printf("\n");
		temp = temp->next;
	}
	return (0);
}

t_env	*save_exp(char **envp)
{
	t_env	*env;
	int		i;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		save_line(&env, envp[i]);
		i++;
	}
	old_pwd(env);
	return (env);
}

static void	old_pwd(t_env *env)
{
	t_env	*temp;

	temp = search_env(env, "OLDPWD");
	if (temp == NULL)
	{
		save_line(&env, "OLDPWD=a");
		temp = search_env(env, "OLDPWD");
		free (temp->line[1]);
		temp->line[1] = NULL;
	}
}
