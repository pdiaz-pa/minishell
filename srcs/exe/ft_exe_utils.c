/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:47:17 by antgonza          #+#    #+#             */
/*   Updated: 2022/01/08 09:09:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_env_lines(t_env *env);

char	**ft_make_argv(t_cont *command)
{
	char	**argv;
	t_cont	*temp;
	int		i;

	temp = command;
	i = 1;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	argv = (char **)malloc(sizeof(char *) * i);
	temp = command;
	i = 0;
	while (temp != NULL)
	{
		argv[i] = temp->content;
		i++;
		temp = temp->next;
	}
	argv[i] = NULL;
	return (argv);
}

char	**ft_make_envp(t_env *env)
{
	char		**envp;
	t_env		*temp;
	char		*temp2;
	int			i;

	i = ft_env_lines(env);
	envp = (char **)malloc(sizeof(char *) * i);
	if (envp == NULL)
		perror("malloc error");
	temp = env;
	i = 0;
	while (temp != NULL)
	{
		if (temp->line[1])
		{
			temp2 = ft_strjoin(temp->line[0], "=");
			envp[i] = ft_strjoin(temp2, temp->line[1]);
			free(temp2);
			i++;
		}
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}

static int	ft_env_lines(t_env *env)
{
	t_env		*temp;
	int			i;

	i = 1;
	temp = env;
	while (temp != NULL)
	{
		if (temp->line[1])
			i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_free_mem(char **arr)
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

int	ft_print_valid_error(char *command)
{
	if (command[0] == '/' || command[0] == '.')
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		g_exit_status = 127;
	}
	else
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		g_exit_status = 127;
	}
	return (0);
}
