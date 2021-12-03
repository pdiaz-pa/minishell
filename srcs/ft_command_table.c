/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:17:15 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/03 12:02:29 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count_pipes(t_mylist *tk_l);

void	ft_command_table(t_env *env, t_mylist *tk_l)
{
	int	nProc;
	t_proc	*proc;
	if (env){}
	
	proc = NULL;
	nProc = ft_count_pipes(tk_l);
	ft_save_command(&proc, tk_l);
}

static int	ft_count_pipes(t_mylist *tk_l)
{
	int			i;
	t_mylist	*temp;

	temp = tk_l;
	i = 1;
	while (temp != NULL)
	{
		if (temp->tk_type == PIPE)
			i++;
		temp = temp->next;
	}
	return (i);
}

