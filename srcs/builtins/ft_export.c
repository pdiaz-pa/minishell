/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/07 20:47:17 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export(char **envp)
{
	/* int	i;
	int next;

	i = 0;
	while (envp [i] && envp[i + 1])
	{
		next = 0;
		if (envp[i + 1][0] < envp[i][0])
			next = i + 1;
		i++;
	} */
	(void)envp;
	printf("%d", ft_strcmp("Hola","Hocb"));
	return (0);
}

/* 
static void	bubble_sort(int *envp)
{
	int		i;
	char	swap;
	int		aux;

	swap = '1';
	while (swap == '1')
	{
		swap = '0';
		i = 0;
		while (i < ps->total - 1)
		{
			if (ps->number[i] > ps->number [i + 1])
			{
				aux = ps->number[i];
				ps->number[i] = ps->number[i + 1];
				ps->number[i + 1] = aux;
				swap = '1';
			}
			i++;
		}
	}
	return ;
} */