/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:38 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/25 18:11:41 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_export_2(t_env **env, char *content);

int	ft_export(t_env **env, t_mylist *tk_l)
{
	t_mylist	*temp;
	char		ret;

	ret = '0';
	if (tk_l == NULL || tk_l->tk_type == 1)
	{
		ft_print_export(*env);
		return (0);
	}
	temp = tk_l;
	while(temp != NULL && temp->tk_type == 0)
	{
		if (ft_isdigit(temp->content[0]))
		{
			printf("minishell: export: `%s': not a valid identifier\n", tk_l->content);
			ret = '1';
		}
		else
			ft_export_2(env, temp->content);
		temp = temp->next;
	}
	if (ret == '1')
		return (1);
	return (0);
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