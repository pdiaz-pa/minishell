/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:50:14 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/25 18:16:48 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	    ft_unset(t_env **env, t_mylist *tk_l)
{
	t_env		*temp;
	t_mylist	*list;
	char		ret;

	temp = *env;
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
		list = list->next;
	}
	if (ret == '1')
		return (1);
	return (0);
}
