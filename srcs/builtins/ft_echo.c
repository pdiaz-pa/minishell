/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:38:02 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/28 17:45:42 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(t_mylist *tk_l)
{
	char	flag;

	flag = '0';
	if (tk_l != NULL && (ft_strcmp(tk_l->content, "-n") == 0))
	{
		flag = '1';
		tk_l = tk_l->next;
	}
	while (tk_l != NULL && tk_l->tk_type == 0)
	{
		printf("%s", tk_l->content);
		if (tk_l->next != NULL && tk_l->next != NULL && tk_l->next->tk_type == 0)
			printf(" ");
		tk_l = tk_l->next;
	}
	if (flag == '0')
		printf("\n");
	return (0);
}