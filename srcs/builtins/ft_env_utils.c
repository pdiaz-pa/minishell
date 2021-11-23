/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:53:38 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/23 09:38:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_search_env(t_env *env, char *name)
{
	t_env	*temp;

	temp = env;
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
		temp = temp->next;
		free(temp2);
		temp2 = NULL;
	}
	*env = NULL;
}

/* void	ft_edit_env(t_env *env, char *content)
{
	
} */


