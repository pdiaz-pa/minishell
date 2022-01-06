/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequoter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:38:38 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/06 03:40:28 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_in_size_calc(t_mylist *tk_l, int size, char quote)
{
	if (tk_l->content[tk_l->i] == SINGLEQ
		|| tk_l->content[tk_l->i] == DOUBLEQ)
	{
		quote = tk_l->content[tk_l->i];
		tk_l->i++;
		while (tk_l->content[tk_l->i] != quote
			&& tk_l->content[tk_l->i] != '\0')
		{
			size++;
			tk_l->i++;
		}
		if (tk_l->content[tk_l->i] == quote)
			tk_l->i++;
	}
	if (tk_l->content[tk_l->i] != '\0' && tk_l->content[tk_l->i] != SINGLEQ
		&& tk_l->content[tk_l->i] != DOUBLEQ)
	{
		tk_l->i++;
		size++;
	}
	return (size);
}

int	ft_size_calc(t_mylist *tk_l)
{
	int		size;
	char	quote;

	tk_l->i = 0;
	size = 0;
	quote = 'x';
	while (tk_l->content[tk_l->i] != '\0')
		size = ft_in_size_calc(tk_l, size, quote);
	return (size);
}

char	*ft_in_dequoter(t_mylist *tk_l, char *temp, char *str, char quote)
{
	if (str[tk_l->i] == SINGLEQ || str[tk_l->i] == DOUBLEQ)
	{
		quote = str[tk_l->i];
		tk_l->i++;
		while (str[tk_l->i] != quote && str[tk_l->i] != '\0')
		{
			temp[tk_l->j] = str[tk_l->i];
			tk_l->j++;
			tk_l->i++;
		}
		if (str[tk_l->i] == quote)
			tk_l->i++;
	}
	if (str[tk_l->i] != '\0' && str[tk_l->i] != SINGLEQ
		&& str[tk_l->i] != DOUBLEQ)
	{
		temp[tk_l->j] = str[tk_l->i];
		tk_l->j++;
		tk_l->i++;
	}
	return (temp);
}

char	*ft_dequoter(t_mylist *tk_l, char *str, int size)
{
	char	*temp;
	char	quote;

	tk_l->i = 0;
	tk_l->j = 0;
	quote = 'x';
	temp = malloc(size + 1);
	while (str[tk_l->i] != '\0')
		temp = ft_in_dequoter(tk_l, temp, str, quote);
	temp[tk_l->j] = '\0';
	return (temp);
}
