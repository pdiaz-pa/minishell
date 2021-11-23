/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:38 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/23 17:24:59 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static void	new_line_env(t_env **env, t_mylist *tk_l);

int	ft_export(t_env **env, t_mylist *tk_l)
{
	t_mylist *temp;

	if (tk_l == NULL || tk_l->tk_type == 1)
		ft_print_export(*env);
	temp = tk_l;
	while(temp != NULL && temp->tk_type == 0)
	{
		if (ft_isdigit(tk_l->content[0]))
			printf("minishell: export: `%s': not a valid identifier\n", tk_l->content);
		else if (ft_search_env(*env, tk_l->content) != NULL)
			printf("\nNO ES NULL\n");
			// ft_edit_env(t_env *env, char *content);
		else
			ft_save_env_line(env, temp->content);
		temp = temp->next;
	}
	return (0);
}

