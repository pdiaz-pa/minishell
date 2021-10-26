/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:15:04 by antgonza          #+#    #+#             */
/*   Updated: 2020/02/12 14:44:52 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Adds the element ’new’ at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		aux = *lst;
		aux = ft_lstlast(aux);
		aux->next = new;
	}
	return ;
}
