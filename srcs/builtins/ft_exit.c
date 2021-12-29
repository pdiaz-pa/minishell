/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:49:21 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/29 09:51:11 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void ft_check_exit(t_cont *command);

void	ft_exit(t_env **env, t_cont *command)
{
	if (command != NULL)
	{
		ft_check_exit(command);
	}
	ft_free_env(env);
	//ft_putendl_fd("exit", 2);
	exit(exit_status);
}

static void ft_check_exit(t_cont *command)
{
	int	i;
	
	i = 0;
	if (command->content[0] == '+' || command->content[0] == '-')
		i++;
	while(command->content[i] != 0)
	{
		if (ft_isdigit((int) command->content[0]) == 0)
		{
			ft_putstr_fd("exit\nminishell: exit: ", 2);
			ft_putstr_fd(command->content, 2);
			ft_putendl_fd(": numeric argument required", 2);
			exit_status = 255;
		}
		i++;
	}
}