/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:10:39 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 12:37:43 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Iterates the list ’lst’ and applies the function ’f’ to the content of each
**	element.  Creates a new list resulting of the successive applications of
**	the function ’f’.  The ’del’ function is used to delete the content of an
**	element if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	aux = new;
	while (lst)
	{
		if (lst->next)
		{
			new->next = ft_lstnew(f(lst->next->content));
			if (new->next == NULL)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			new = new->next;
		}
		lst = lst->next;
	}
	new->next = NULL;
	return (aux);
}
