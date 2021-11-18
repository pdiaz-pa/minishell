/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:38:02 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/18 16:41:20 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(t_list *tk_l)
{
	char	flag;
	int		i;

	flag = '0';
	i = 0;
	if ((ft_strcmp(tk_l->content, "-n") == 0))
	{
		flag = '1';
		tk_l = tk_l->next;
	}
	while (tk_l != NULL && ft_strcmp(tk_l->content, "|") != 0)
	{
		printf("%s", tk_l->content);
		if (tk_l->next != NULL)
			printf(" ");
		tk_l = tk_l->next;
	}
	if (flag == '0')
		printf("\n");
	return ;
}