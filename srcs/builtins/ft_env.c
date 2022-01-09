/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:47:47 by antgonza          #+#    #+#             */
/*   Updated: 2022/01/09 21:47:53 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_empty_environment(t_env **env);

t_env	*ft_save_env(char **envp)
{
	t_env	*env;
	t_env	*temp;
	int		i;

	i = 0;
	env = NULL;
	ft_save_env_line(&env, "");
	if (envp[0] == NULL)
		ft_empty_environment(&env);
	else
	{
		while (envp[i])
		{
			ft_save_env_line(&env, envp[i]);
			i++;
		}
		ft_shlvl(env);
		temp = ft_search_env(env, "OLDPWD");
		if (temp == NULL)
			ft_save_env_line(&env, "OLDPWD");
	}
	return (env);
}

void	ft_save_env_line(t_env **env, char *envp)
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

char	**ft_split_env(char const *s)
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

int	ft_print_env(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp != NULL)
	{
		if (temp->line[1])
			printf("%s=%s\n", temp->line[0], temp->line[1]);
		temp = temp->next;
	}
	return (0);
}

static void	ft_empty_environment(t_env **env)
{
	char	*temp;
	char	*temp2;

	temp = getcwd(NULL, 0);
	temp2 = ft_strjoin("PWD=", temp);
	ft_save_env_line(env, temp2);
	free (temp2);
	temp2 = ft_strjoin("_=", temp);
	free (temp);
	temp = ft_strjoin(temp2, "/./minishell");
	free(temp2);
	ft_save_env_line(env, temp);
	free (temp);
	ft_save_env_line(env, "SHLVL=1");
	ft_save_env_line(env, "OLDPWD");
	return ;
}
