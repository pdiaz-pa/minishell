/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:30:19 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/28 18:46:05 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
static void	valid_cmd(t_env *env, char *cmd, char **final);
static void	free_mem(char **arr);


void	ft_exe(t_env **env, t_mylist *tk_l)
{
	pid_t	pid;
	char	*final;
	int		status;
	char	**splitarg;

	final = NULL;
	valid_cmd(ft_search_env(env, "PATH"), path, &final);
	 if (final == NULL)
	{
		if (path[0] == '/')
			printf("minishell: %s: No such file or directory\n", path);
		else
			printf("minishell: %s: command not found\n", path);
		return ;
	} */
/*	splitarg = ft_split(path, ' ');
	pid = fork();
	if (pid == -1)
		perror("pid error");
	else if (pid == 0)
	{
		if (execve(final, splitarg, envp) == -1)
			perror("execve");
	}
	else if (pid > 0)
	{
		pid = waitpid(-1, &status, 0);
		free_mem(splitarg);
		free(final);
	}
}

static void	valid_cmd(t_env *env, char *cmd, char **final)
{
	int		i;
	char	**path;
	char	*tmp[2];

	if (access(cmd, F_OK) != -1)
	{
		*final = ft_strdup(cmd);
		return ;
	}
	path = ft_split(env->line[1], ':');
	i = 0;
	while (path[i])
	{
		tmp[0] = ft_strjoin(path[i], "/");
		tmp[1] = ft_strjoin(tmp[0], cmd);
		free(tmp[0]);
		tmp[0] = NULL;
		if (access(tmp[1], F_OK) != -1)
		{
			*final = tmp[1];
			break ;
		}
		free(tmp[1]);
		tmp[1] = NULL;
		i++;
	}
	free_mem(path);
}

static void	free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		arr[i] = NULL;
		i++;
	}
	free (arr);
	arr = NULL;
}
*/