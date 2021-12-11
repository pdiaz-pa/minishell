/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:17:15 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/11 12:44:23 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_syntax_error(t_mylist *tk_l);
static int	ft_count_pipes(t_mylist *tk_l);
static void ft_free_ct(t_proc **proc);
// static void	ft_fd_manager(t_proc *new);


void	ft_command_table(t_env *env, t_mylist *tk_l)
{
	t_proc	*proc;
	int		nProc;
	int		i;
	
	if (env){}// eliminar
	if (tk_l == NULL || ft_syntax_error(tk_l) > 0)
		return ;
	i = 1;
	proc = NULL;
	nProc = ft_count_pipes(tk_l);
	while (i <= nProc)
	{
		ft_save_command(&proc, tk_l, nProc, i);
		i++;
	}
	
	
	t_proc	*temp;
	temp = proc;
	while (temp != NULL)
	{
		// if (temp->total > 1)
			// ft_fd_manager(temp);
		ft_prompt_cmp(env, temp->list);
		temp = temp->next; 

	}
	
	temp = proc;
	t_cont	*t2;
	while (temp != NULL)
	{
		t2 = temp->list;
		printf("prev: %p t:%d n:%d i:%c i2:%c o:%c o2:%c input:%s output:%s next:%p\n",temp->prev, temp->total, temp->num, temp->in, temp->in2, temp->out, temp->out2, temp->input ,temp->output ,temp->next);
		while (t2 != NULL)
		{
			printf("%s ", t2->content);
			t2 = t2->next;
		}
		printf("\n");
		temp = temp->next;
	}
	ft_free_ct(&proc);
}

static int	ft_syntax_error(t_mylist *tk_l)
{
	t_mylist	*temp;
	int			i;

	temp = tk_l;
	i = 0;
	while (temp != NULL)
	{
		if ((temp->tk_type == 1 || temp->tk_type == 2) && temp->next == NULL && i++)
			printf("minishell: aun no se que poner aqui'\n"); // revisar
		if (temp->tk_type == 2 && temp->next == NULL && i++)
			printf("minishell: syntax error near unexpected token `newline'\n");
		if (temp->tk_type == 2 && temp->next != NULL && temp->next->tk_type == 1 && i++)
			printf("minishell: syntax error near unexpected token `|'\n");
		if (temp->tk_type == 1 && temp->next == NULL && i++)
			printf("minishell: syntax error `|' end not support\n");
		temp = temp->next;
	}
	return (i);
}

static int	ft_count_pipes(t_mylist *tk_l)
{
	int			i;
	t_mylist	*temp;

	temp = tk_l;
	i = 1;
	while (temp != NULL)
	{
		if (temp->tk_type == PIPE && temp->next != NULL)
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
		/* if (temp->num < temp->total)
		{
		close(temp->fd[0]);
		close(temp->fd[1]);
		} */
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
 
/* static void	ft_fd_manager(t_proc *new)
{
if (new->num == 1)
		{
			pipe(new->fd);
			close(new->fd[0]);
			dup2(new->fd[1], STDOUT_FILENO);
			close(new->fd[1]);
		}
		else if (new->num > 1 && new->num < new->total)
		{
			pipe(new->fd);
			close(new->fd[0]);
			dup2(new->prev->fd[0], STDIN_FILENO);
			close(new->prev->fd[0]);
			dup2(new->fd[1], STDOUT_FILENO);
			close(new->fd[1]);
		}
		else if (new->num ==  new->total)
		{
			dup2(new->prev->fd[0], STDIN_FILENO);
			close(new->prev->fd[0]);
		}
} */