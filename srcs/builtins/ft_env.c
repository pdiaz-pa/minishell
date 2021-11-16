/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:47:47 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/16 14:15:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	save_line_env(t_env **env, char *envp);
static char	**ft_split_env(char const *s);

t_env	*save_env(char **envp)
{
	t_env	*env;
	int		i;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		save_line_env(&env, envp[i]);
		i++;
	}
	// old_pwd(env);
	return (env);
}

static void	save_line_env(t_env **env, char *envp)
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
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
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
	if (s[i] == '=')
		split[1] = ft_substr(s, i + 1, len - (i + 1));
	else
		split[1] = NULL;
	split[2] = NULL;
	return (split);
}
/* 
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
} */

int	ft_print_env(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL)
	{
		printf("%s=%s\n", temp->line[0], temp->line[1]);
		temp = temp->next;
	}
	return (0);
}