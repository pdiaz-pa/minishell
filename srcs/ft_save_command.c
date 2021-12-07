/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:01:40 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/06 17:52:44 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_init_proc(t_proc **proc, t_proc *new, int total, int num);
static t_mylist	*ft_advance_list(t_mylist *tk_l, int num);
static void	ft_analize_command(t_proc *new, t_mylist *tk_l);
static void	ft_save_line(t_proc *proc, char *content);

void	ft_save_command(t_proc **proc,	t_mylist *tk_l, int total, int num)
{
	t_proc	*new;
	t_proc	*temp;

	new = malloc(sizeof (t_proc));
	if (new == NULL)
		perror("malloc error");
	ft_init_proc(proc, new, total, num);
	ft_analize_command(new, ft_advance_list(tk_l, num));
	if (*proc == NULL)
		*proc = new;
	else
	{
	temp = *proc;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	}
}

static void	ft_init_proc(t_proc **proc, t_proc *new, int total, int num)
{
	t_proc	*temp;

	temp = *proc;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	new->prev = temp;
	new->total = total;
	new->num = num;
	new->in = '0';
	new->in2 = '0';
	new->out = '0';
	new->out2 = '0';
	new->input = NULL;
	new->output = NULL;
	new->list	= NULL;
	new->next = NULL;

	return ;
}

static t_mylist	*ft_advance_list(t_mylist *tk_l, int num)
{
	t_mylist	*temp;
	int			i;

	i = 1;
	temp = tk_l;
	while (temp != NULL && i < num)
	{
		if (temp->tk_type == 1)
			i++;
		temp = temp->next;
	}
	return (temp);
}

static void	ft_analize_command(t_proc *new, t_mylist *tk_l)
{
	t_mylist *temp;

	temp = tk_l;
	while (temp != NULL && temp->tk_type != 1)
	{
		if (temp->tk_type == 2)
		{
			if (ft_strcmp(temp->content, "<") == 0)
			{
				new->in = '1';
				temp = temp->next;
				new->input = temp->content;
			}
			else if (ft_strcmp(temp->content, "<<") == 0)
				new->in2 = '1';
			else if (ft_strcmp(temp->content, ">") == 0)
			{
				new->out = '1';
				temp = temp->next;
				new->output = temp->content;
			}
			else if (ft_strcmp(temp->content, ">>") == 0)
			{
				new->out2 = '1';
				temp = temp->next;
				new->output = temp->content;
			}
		}
		else if (temp->tk_type == 0)
			ft_save_line(new, temp->content);
		temp = temp->next;
	}
}

static void	ft_save_line(t_proc *proc, char *content)
{
	t_cont	*new;
	t_cont	*temp;

	new = malloc(sizeof (t_cont));
	if (new == NULL)
		perror("malloc error");
	new->content = content;
	new->next = NULL;
	if (proc->list == NULL)
		proc->list = new;
	else
	{
	temp = proc->list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	}
}

