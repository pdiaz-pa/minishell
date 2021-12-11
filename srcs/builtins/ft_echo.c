/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:38:02 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/11 12:43:06 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(t_cont *command)
{
	char	flag;

	flag = '0';
	if (command != NULL && (ft_strcmp(command->content, "-n") == 0))
	{
		while (ft_strcmp(command->content, "-n") == 0)
			command = command->next;
		flag = '1';
	}
	while (command != NULL)
	{
		printf("%s", command->content);
		if (command->next != NULL)
			printf(" ");
		command = command->next;
	}
	if (flag == '0')
		printf("\n");
	return (0);
}