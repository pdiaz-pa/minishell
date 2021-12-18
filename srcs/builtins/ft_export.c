/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:38 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/18 19:09:41 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_export_2(t_env **env, char *content);

int	ft_export(t_env **env, t_cont *command)
{
	t_cont	*temp;
	int		ret;

	ret = 0;
	if (command == NULL)
	{
		ft_print_export(*env);
		return (0);
	}
	temp = command;
	while (temp != NULL)
	{
		if (ft_isdigit(temp->content[0]))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(command->content, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			ret = 1;
		}
		else
			ft_export_2(env, temp->content);
		temp = temp->next;
	}
	return (ret);
}

static void	ft_export_2(t_env **env, char *content)
{
	t_env	*temp;
	char	**split;

	split = ft_split_env(content);
	temp = ft_search_env(*env, split[0]);
	if (temp != NULL)
	{
		if (split[1] != NULL)
		{
			if (temp->line[1] != NULL)
				free(temp->line[1]);
			temp->line[1] = split[1];
		}
	}
	else
	{
		if (split[1] != NULL)
			free(split[1]);
		ft_save_env_line(env, content);
	}
	free(split[0]);
	free(split);
	return ;
}
