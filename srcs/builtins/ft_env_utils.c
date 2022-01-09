/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:53:38 by antgonza          #+#    #+#             */
/*   Updated: 2022/01/09 22:17:38 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_is_valid(char *line);

t_env	*ft_search_env(t_env *env, char *name)
{
	t_env	*temp;

	temp = env->next;
	while (temp != NULL && (ft_strcmp(temp->line[0], name) != 0))
		temp = temp->next;
	return (temp);
}

void	ft_free_env(t_env **env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = *env;
	while (temp != NULL)
	{
		temp2 = temp;
		free(temp->line[0]);
		temp->line[0] = NULL;
		if (temp->line[1] != NULL)
			free(temp->line[1]);
		temp->line[1] = NULL;
		free(temp->line);
		temp->line = NULL;
		temp = temp->next;
		free(temp2);
		temp2 = NULL;
	}
}

void	ft_shlvl(t_env *env)
{
	t_env	*temp;
	int		value;

	temp = ft_search_env(env, "SHLVL");
	if (temp == NULL)
		ft_save_env_line(&env, "SHLVL=1");
	else
	{
		if (temp->line[1] == NULL || ft_is_valid(temp->line[1]) == 1)
			value = 0;
		else
			value = ft_atoi(temp->line[1]);
		value++;
		if (temp->line[1] != NULL)
			free(temp->line[1]);
		temp->line[1] = ft_itoa(value);
	}
}

static int	ft_is_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_isdigit(line[i])))
			return (1);
		i++;
	}
	return (0);
}
