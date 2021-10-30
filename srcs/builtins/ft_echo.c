/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:38:02 by antgonza          #+#    #+#             */
/*   Updated: 2021/10/30 09:23:50 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **argv)
{
	char	flag;
	int		i;

	flag = '0';
	i = 0;
	if ((ft_strcmp(argv[i], "-n") == 0))
	{
		flag = '1';
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	if (flag == '0')
		printf("\n");
	return ;
}