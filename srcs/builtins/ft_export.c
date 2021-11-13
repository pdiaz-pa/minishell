/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/13 21:15:13 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_line(t_env **env, char *envp);
// static t_env	**short_line(t_env **env, char *envp)
;

int	ft_export(t_env *env)
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

t_env	*save_env(char **envp)
{
	t_env	*env;
	int		i;
	char	find;

	i = 0;
	env = NULL;
	while(envp[i])
	{
		save_line(&env, envp[i]);
		i++;
	}
	i = 0;
	find = '0';
	while(envp[i])
	{
		if (ft_strncmp("OLDPWD=", envp[i], 7) == 0)
			find = '1';
		i++;
	}
	if (find == '0')
		save_line(&env, "OLDPWD");
	return (env);
}

static void	save_line(t_env **env, char *envp)
{
	t_env	*new;
	t_env	*temp;
	t_env	*temp2;

	new = malloc(sizeof (t_env));
	if (new == NULL)
		perror("malloc error");
	new->line = ft_split(envp, '=');
	new->next = NULL;
	if (*env == NULL)
		*env = new;
	else
	{
		temp = *env;
		if (temp != NULL && ft_strcmp(new->line[0], temp->line[0]) < 0)
		{
			*env = new;
			new->next = temp;
		}
		while(temp->next != NULL && ft_strcmp(new->line[0], temp->next->line[0]) > 0)
			temp = temp->next;
		if (temp->next == NULL && ft_strcmp(new->line[0], temp->line[0]) > 0)
			temp->next = new;
		else
		{
			temp2 = temp->next;
			temp->next = new;
			new->next = temp2;
		}
	}
}

/* static t_env	**short_line(t_env **env, char *envp)
{
	t_env	*temp;

	temp = *env;
	if (ft_strncmp(env))
	return (&temp);
}
 */