/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:10:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/11 11:53:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_cd_home(t_env **env);
static void	ft_update_pwd(t_env **env, char *old);

int	ft_cd(t_env **env,  t_cont *command)
{
	int		ret;
	char	*old;

	ret = 0;
	old = getcwd(NULL, 0);
	if (command == NULL /* || (ft_strcmp(tk_l->content, "~")) == 0 */)
		ret = ft_cd_home(env);
	else 
	{
		if ((chdir(command->content)) == -1)
		{
			printf("minishell: cd: %s: No such file or directory\n",
				command->content);
			ret++;
		}
	}
	if (ret == 0)
		ft_update_pwd(env, old);
	free (old);
	return (ret);
}

static int	ft_cd_home(t_env **env)
{
	t_env	*temp;

	temp = ft_search_env(*env, "HOME");
	if (temp == NULL)
	{
		printf("minishell: cd: HOME not set\n");
		return (1);
	}
	else
	{
		if((chdir(temp->line[1])) == -1)
		{
			printf("minishell: cd: %s: No such file or directory\n",
				temp->line[1]);
			return (1);
		}
	}
	return (0);
}

static void	ft_update_pwd(t_env **env, char *old)
{
	t_env	*temp;
	char	*pwd;

	temp = ft_search_env(*env, "OLDPWD");
	if (temp != NULL)
	{
		if (temp->line[1] != NULL)
			free (temp->line[1]);
		temp->line[1] = ft_strdup(old);
	}
	temp = ft_search_env(*env, "PWD");
	if (temp != NULL)
	{
		if (temp->line[1] != NULL)
			free(temp->line[1]);
		pwd = getcwd(NULL, 0);
		temp->line[1] = ft_strdup(pwd);
		free (pwd);
	}
	return ;
}