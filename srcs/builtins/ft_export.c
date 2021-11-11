/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/11 14:47:53 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	bubble_sort(char **copy, int lines);

void	save_env(t_env *env)
{

}

int	ft_export(char **envp)
{
	int	i;
	int	lines;
	char	**copy;

	lines = 0;
	while (envp [lines])
		lines++;
	copy = malloc(sizeof(char *) * lines);
	i = -1;
	while (++i < lines)
		copy[i] = envp[i];
	i = -1;
	while (++i < lines)
		printf("%s\n", copy[i]);
	bubble_sort(copy, lines);
	//printf("%d\n", ft_strcmp("a","z"));
	printf("getenv = %s", getenv("PWD"));
	return (0);
}


static void	bubble_sort(char **copy, int lines)
{
	int		i;
	char	swap;
	//char	*aux;

	swap = '1';
	while (swap == '1')
	{
		swap = '0';
		i = 0;
		while (i < lines - 1)
		{
			if ((ft_strcmp(copy[i], copy[i + 1])) < 0)
			{
			/* 	aux = ps->number[i];
				ps->number[i] = ps->number[i + 1];
				ps->number[i + 1] = aux;
				swap = '1'; */
			}
			i++;
		}
	}
	return ;
}