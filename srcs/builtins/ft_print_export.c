/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/18 18:55:22 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_env	*ft_save_exp(t_env *env);
static void		ft_free_export(t_env **env);
static void		ft_save_line(t_env **env, char **line);
static void		ft_save_line_2(t_env *new, t_env *temp);

int	ft_print_export(t_env *env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = ft_save_exp(env);
	temp2 = temp;
	while (temp2 != NULL)
	{
		printf("declare -x %s", temp2->line[0]);
		if (temp2->line[1])
			printf("=\"%s\"\n", temp2->line[1]);
		else
			printf("\n");
		temp2 = temp2->next;
	}
	ft_free_export(&temp);
	return (0);
}

static t_env	*ft_save_exp(t_env *env)
{
	t_env	*ret;
	t_env	*temp;

	ret = NULL;
	temp = env;
	while (temp != NULL)
	{
		ft_save_line(&ret, temp->line);
		temp = temp->next;
	}
	return (ret);
}

static void	ft_save_line(t_env **env, char **line)
{
	t_env	*new;
	t_env	*temp;

	new = malloc(sizeof (t_env));
	if (new == NULL)
		perror("malloc error");
	new->line = line;
	new->next = NULL;
	if (*env == NULL)
		*env = new;
	else
	{
		temp = *env;
		if (temp != NULL && ft_strcmp(new->line[0], temp->line[0]) < 0)
		{
			*env = new;
			new->next = temp;
		}
		else
			ft_save_line_2(new, temp);
	}
}

static void	ft_save_line_2(t_env *new, t_env *temp)
{
	t_env	*temp2;

	while (temp->next != NULL && ft_strcmp(new->line[0],
			temp->next->line[0]) > 0)
		temp = temp->next;
	if (temp->next == NULL && ft_strcmp(new->line[0], temp->line[0]) > 0)
		temp->next = new;
	else
	{
		temp2 = temp->next;
		temp->next = new;
		new->next = temp2;
	}
}

static void	ft_free_export(t_env **env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = *env;
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
		temp2 = NULL;
	}
}
