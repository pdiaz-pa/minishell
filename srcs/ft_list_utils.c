/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:23:51 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/05 01:03:53 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_mylist	*ft_mylstlast(t_mylist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stack_printer(t_mylist *stack)
{
	stack = stack->next;
	while (stack != NULL)
	{
		printf("%s->", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	ft_mylstadd_back(t_mylist **lst, t_mylist *new)
{
	t_mylist	*aux;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		aux = *lst;
		aux = ft_mylstlast(aux);
		aux->next = new;
	}
	return ;
}

char	*ft_dollarizer(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\0')
	{
		if (content[i] == FKDOLLAR)
			content[i] = '$';
		i++;
	}
	return (content);
}

t_mylist	*ft_mylstnew(void *content, int isexp)
{
	t_mylist	*new;

	new = malloc(sizeof(t_mylist));
	if (new == NULL)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	new->nonexp = NULL;
	new->isexp = isexp;
	return (new);
}
