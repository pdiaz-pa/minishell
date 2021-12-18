/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:50:14 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/18 19:36:46 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_unset_2(t_env **env, t_env *unset);

int	ft_unset(t_env **env, t_cont *command)
{
	t_env	*unset;
	t_cont	*list;
	int		ret;

	ret = 0;
	if (command == NULL)
		return (ret);
	list = command;
	while (list != NULL)
	{
		if (ft_strchr(list->content, '=') != NULL)
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(list->content, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			ret = 1;
		}
		unset = ft_search_env(*env, list->content);
		if (unset != NULL)
			ft_unset_2(env, unset);
		list = list->next;
	}
	return (ret);
}

static void	ft_unset_2(t_env **env, t_env *unset)
{
	t_env	*temp;

	temp = *env;
	if (temp == unset)
		*env = temp->next;
	else
	{
		while (temp->next != unset)
			temp = temp->next;
		temp->next = unset->next;
	}
	free (unset->line[0]);
	unset->line[0] = NULL;
	if (unset->line[1] != NULL)
		free (unset->line[1]);
	unset->line[1] = NULL;
	free (unset->line);
	unset->line = NULL;
	free (unset);
	unset = NULL;
	return ;
}
