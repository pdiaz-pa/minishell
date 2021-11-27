/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:50:14 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/26 12:03:41 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_unset_2(t_env **env, t_env *unset);

int	    ft_unset(t_env **env, t_mylist *tk_l)
{
	t_env		*unset;
	t_mylist	*list;
	char		ret;

	ret = '0';
	if (tk_l == NULL || tk_l->tk_type == 1)
		return 0;
	list = tk_l;
	while(list != NULL && list->tk_type == 0)
	{
		if (ft_strchr(list->content, '=') != NULL)
		{
			printf("minishell: unset: `%s': not a valid identifier\n", tk_l->content);
			ret = '1';
		}
		unset = ft_search_env(*env, list->content);
		if (unset != NULL)
			ft_unset_2(env, unset);
		list = list->next;
	}
	if (ret == '1')
		return (1);
	return (0);
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
	if (unset->line[1] != NULL)
		free (unset->line[1]);
	free (unset);
	return ;
}
