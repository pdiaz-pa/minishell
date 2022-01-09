/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:17:15 by antgonza          #+#    #+#             */
/*   Updated: 2022/01/09 01:55:29 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_syntax_error(t_mylist *tk_l);
static int	ft_count_pipes(t_mylist *tk_l);
static void	ft_free_ct(t_proc **proc);
static void	ft_free_cont(t_cont **cont);

void	ft_command_table(t_env *env, t_mylist *tk_l)
{
	t_proc	*proc;
	t_proc	*temp;
	int		n_proc;
	int		i;

	if (tk_l == NULL || (ft_syntax_error(tk_l)) != 0)
		return ;
	i = 1;
	proc = NULL;
	n_proc = ft_count_pipes(tk_l);
	while (i <= n_proc)
	{
		ft_save_command(&proc, tk_l, n_proc, i);
		i++;
	}
	temp = proc;
	while (temp != NULL)
	{
		if (temp->total > 1)
			ft_process_manager(env, temp);
		else
			ft_single_process(env, temp);
		temp = temp->next;
	}
	ft_free_ct(&proc);
}

static int	ft_syntax_error(t_mylist *tk_l)
{
	t_mylist	*temp;

	temp = tk_l;
	while (temp != NULL)
	{
		if (temp->tk_type == 1 && temp->next == NULL)
		{
			ft_putendl_fd("minishell: syntax error near unexpected token `|'",
				2);
			return (1);
		}
		else if (temp->tk_type == 2 && temp->next == NULL)
		{
			ft_putendl_fd
				("minishell: syntax error near unexpected token `newline'", 2);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
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

static void	ft_free_ct(t_proc **proc)
{
	t_proc	*temp;
	t_proc	*temp2;

	temp = *proc;
	while (temp != NULL)
	{
		ft_free_cont(&temp->list);
		temp2 = temp;
		temp = temp->next;
		free (temp2);
	}
}

static void	ft_free_cont(t_cont **cont)
{
	t_cont	*temp;
	t_cont	*temp2;

	temp = *cont;
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
		free (temp2);
		temp2 = NULL;
	}
	return ;
}
