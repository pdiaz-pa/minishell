/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:17:15 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/02 11:18:08 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count_pipes(t_mylist *tk_l);

void	ft_command_table(t_env *env, t_mylist *tk_l)
{
	int	nProc;
	t_proc	**proc;
	if (env){}
	
	nProc = ft_count_pipes(tk_l);
	proc = (t_proc **)malloc(sizeof (t_proc) * nProc + 1);
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