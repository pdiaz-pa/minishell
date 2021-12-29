/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:49:21 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/29 12:17:31 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_check_exit(t_cont *command);

int	ft_exit(t_env **env, t_cont *command)
{
	int	check;

	if (command != NULL)
	{
		check = ft_check_exit(command);
		if (check == 1)
			return (1);
		else if (check == 2)
		{
			ft_free_env(env);
			exit(exit_status);
		}
		else
			exit_status = ft_atoi(command->content);
	}
	ft_free_env(env);
	ft_putendl_fd("exit", 2);
	exit(exit_status);
	return (0);
}

static int	ft_check_exit(t_cont *command)
{
	int	i;

	i = 0;
	if (command->content[0] == '+' || command->content[0] == '-')
		i++;
	while (command->content[i] != 0)
	{
		if (ft_isdigit((int) command->content[0]) == 0)
		{
			ft_putstr_fd("exit\nminishell: exit: ", 2);
			ft_putstr_fd(command->content, 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit_status = 255;
			return (2);
		}
		i++;
	}
	if (command->next != NULL)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		exit_status = 1;
		return (1);
	}
	return (0);
}
