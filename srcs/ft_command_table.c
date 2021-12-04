/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:17:15 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/04 15:47:20 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count_pipes(t_mylist *tk_l);

void	ft_command_table(t_env *env, t_mylist *tk_l)
{
	int		nProc;
	t_proc	*proc;
	int		i;
	if (env){}
	
	i = 0;
	proc = NULL;
	nProc = ft_count_pipes(tk_l);
	while (++i <= nProc)
		ft_save_command(&proc, tk_l, nProc, i);
	
	
	
	t_proc	*temp;
	// t_cont	*t2;
	temp = proc;
	while (temp != NULL)
	{
		ft_prompt_cmp(env, temp->list);
		temp = temp->next; 

	}
	/* while (temp != NULL)
	{
		t2 = temp->list;
		printf("t:%d n:%d i:%c i2:%c o:%c o2:%c input:%s output:%s next:%p\n", temp->total, temp->num, temp->in, temp->in2, temp->out, temp->out2, temp->input ,temp->output ,temp->next);
		while (t2 != NULL)
		{
			printf("%s ", t2->content);
			t2 = t2->next;
		}
		printf("\n");
		temp = temp->next;
	} */
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
 
