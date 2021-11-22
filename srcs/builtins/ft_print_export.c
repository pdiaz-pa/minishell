/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 07:42:26 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/22 17:49:16 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static void	old_pwd(t_env *env);
static t_env	*save_exp(t_env *env);
static void	free_export(t_env **env);
static void	save_line(t_env **env, char **line);
static void	save_line_2(t_env *new, t_env *temp);


int	ft_print_export(t_env *env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = save_exp(env);
	temp2 = temp;
	while (temp2 != NULL)
	{
		printf("declare -x ");
		printf("%s", temp2->line[0]);
		if (temp2->line[1])
		{
			printf("=\"");
			printf("%s", temp2->line[1]);
			printf("\"\n");
		}
		else
			printf("\n");
		temp2 = temp2->next;
	}
	free_export(&temp);
	return (0);
}

static t_env	*save_exp(t_env *env)
{
	t_env	*ret;
	t_env	*temp;
	char	**old;

	ret = NULL;
	temp = env;
	while (temp != NULL)
	{
		save_line(&ret, temp->line);
		temp = temp->next;
	}
	temp = search_env(ret, "OLDPWD");
	if (temp == NULL)
	{
		old = (char **)malloc(sizeof(char *) * 2);
		if (old == NULL)
			perror ("Malloc fail");
		old[0] = ft_strdup("OLDPWD");
		old[1] = NULL;
		save_line(&ret, old);
	}
	return (ret);
}

static void	save_line(t_env **env, char **line)
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
			save_line_2(new, temp);
	}
}

static void	save_line_2(t_env *new, t_env *temp)
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

static void	free_export(t_env **env)
{
	t_env	*temp;
	t_env	*temp2;

	temp2 = *env;
	temp = search_env(temp2, "OLDPWD");
	if (temp->line[1] == NULL)
	{
		free (temp->line[0]);
		free (temp->line);
	}
	temp = *env;
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*env = NULL;
}