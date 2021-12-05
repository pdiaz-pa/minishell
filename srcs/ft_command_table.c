/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:17:15 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/05 09:36:31 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_count_pipes(t_mylist *tk_l);
static void ft_free_ct(t_proc **proc);

void	ft_command_table(t_env *env, t_mylist *tk_l)
{
	t_proc	*proc;
	int		nProc;
	int		i;
	
	if (env){}//
	if (tk_l == NULL)
		return;
	i = 1;
	proc = NULL;
	nProc = ft_count_pipes(tk_l);
	while (i <= nProc)
	{
		ft_save_command(&proc, tk_l, nProc, i);
		i++;
	}
	
	
	
	t_proc	*temp;
	// t_cont	*t2;
	temp = proc;
	while (temp != NULL)
	{
		//ft_prompt_cmp(env, temp->list);
		temp = temp->next; 

	}
	ft_free_ct(&proc);
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

static void ft_free_ct(t_proc **proc)
{
	t_proc	*temp;
	t_proc	*temp2;
	t_cont	*ctemp;
	t_cont	*ctemp2;

	temp = *proc;
	while (temp != NULL)
	{
		ctemp = temp->list;
		while(ctemp != NULL)
		{
			ctemp2 = ctemp;
			ctemp = ctemp->next;
			free (ctemp2);
		}
		temp2 = temp;
		temp = temp->next;
		free (temp2);
	}

}
 
