/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:30:19 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/04 15:34:58 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	valid_cmd(t_env *env, char *cmd, char **final);
static void	valid_cmd_2(t_env *env, char *cmd, char **final);
static void	ft_free_mem(char **arr);
static void	ft_execve(char *cmd, char **argv, char **envp);

void	ft_exe(t_env *env, t_cont *command)
{
	char	*final;
	char	**argv;
	char	**envp;

	final = NULL;
	valid_cmd(ft_search_env(env, "PATH"), command->content, &final);
	if (final == NULL)
	{
		if (command->content[0] == '/')
			printf("minishell: %s: No such file or directory\n", command->content);
		else
			printf("minishell: %s: command not found\n", command->content);
	}
	else
	{
		argv = ft_make_argv(command);
		envp = ft_make_envp(env);
		ft_execve(final, argv, envp);
		free(final);
		free(argv);
		ft_free_mem(envp);
	}
	return ;
}

static void	valid_cmd(t_env *env, char *cmd, char **final)
{
	if (access(cmd, F_OK) != -1)
		*final = ft_strdup(cmd);
	else if (env == NULL)
		return ;
	else
		valid_cmd_2(env, cmd, final);
	return ;
}

static void	valid_cmd_2(t_env *env, char *cmd, char **final)
{
	int		i;
	char	**path;
	char	*tmp;
	char	*check;

	path = ft_split(env->line[1], ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		check = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = NULL;
		if (access(check, F_OK) != -1)
		{
			*final = check;
			break ;
		}
		free(check);
		check = NULL;
		i++;
	}
	ft_free_mem(path);
	return ;
}

static void	ft_free_mem(char **arr)
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

static void	ft_execve(char *cmd, char **argv, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		perror("pid error");
	else if (pid == 0)
	{
		if (execve(cmd, argv, envp) == -1)
			perror("execve");
	}
	else if (pid > 0)
	{
		pid = waitpid(-1, &status, 0);
	}
}
