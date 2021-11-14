/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:53:38 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/14 14:19:29 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_line_2(t_env *new, t_env *temp);
static char	**ft_split_env(char const *s);

void	save_line(t_env **env, char *envp)
{
	t_env	*new;
	t_env	*temp;

	new = malloc(sizeof (t_env));
	if (new == NULL)
		perror("malloc error");
	new->line = ft_split_env(envp);
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

t_env	*search_env(t_env *env, char *name)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL && (ft_strcmp(temp->line[0], name) != 0))
		temp = temp->next;
	return (temp);
}

void	free_env(t_env **env)
{
	t_env	*temp;
	t_env	*temp2;

	temp = *env;
	while (temp != NULL)
	{
		temp2 = temp;
		free(temp->line[0]);
		temp->line[0] = NULL;
		free(temp->line[1]);
		temp->line[1] = NULL;
		temp = temp->next;
		free(temp2);
		temp2 = NULL;
	}
	*env = NULL;
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

static char	**ft_split_env(char const *s)
{
	char	**split;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * 3);
	if (split == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i] != '\0' && (s[i] != '='))
		i++;
	split[0] = ft_substr(s, 0, i);
	split[1] = ft_substr(s, i + 1, len - (i + 1));
	split[2] = NULL;
	return (split);
}
