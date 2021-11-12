/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/12 12:44:21 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	bubble_sort(char **copy, int lines);
static void	save_line(t_env **env, char *envp);

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

t_env	*save_env(char **envp)
{
	t_env	*env;
	t_env	*temp;
	int		i;

	i = 0;
	env = NULL;
	printf("ENTRA\n");
	while(envp[i])
	{
		save_line(&env, envp[i]);
		i++;
	}
	temp = env;
	while (temp != NULL)
	{
		printf("%s\n", temp->line[0]);
		temp = temp->next;
	}
	return (env);
}

static void	save_line(t_env **env, char *envp)
{
	t_env	*temp;
	t_env	*new;

	new = malloc(sizeof (t_env));
	new->line = ft_split(envp, '=');
	new->next = NULL;
	temp = *env;
	if (*env == NULL)
		*env = new;
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
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