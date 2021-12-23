/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:38:02 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/23 11:36:14 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(t_cont *command)
{
	char	flag;

	flag = '0';
	if (command != NULL && (ft_strcmp(command->content, "-n") == 0))
	{
		while (command != NULL && ft_strcmp(command->content, "-n") == 0)
			command = command->next;
		flag = '1';
	}
	while (command != NULL)
	{
		ft_putstr_fd(command->content, STDOUT_FILENO);
		if (command->next != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
		command = command->next;
	}
	if (flag == '0')
		ft_putstr_fd("\n\0", STDOUT_FILENO);
	return (0);
}
