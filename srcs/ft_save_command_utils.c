/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_command_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:24:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/12 16:53:17 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_check_in_access(t_proc *process, t_mylist *temp);
static int	ft_check_out_access(t_proc *process, t_mylist *temp);

void	ft_check_redir(t_proc *process, t_mylist *temp)
{
	if (process->err == '1')
		return ;
	if (ft_strcmp(temp->content, "<") == 0 && ft_check_in_access(process, temp->next) == 0)
	{
		process->in = '1';
		process->in2 = '0';
		process->input = temp->next->content;
	}
	else if (ft_strcmp(temp->content, "<<") == 0 && ft_check_in_access(process, temp->next) == 0)
	{
		process->in = '0';
		process->in2 = '1';
		process->input = temp->next->content;
	}
	else if (ft_strcmp(temp->content, ">") == 0 && ft_check_out_access(process, temp->next) == 0)
	{
		process->out = '1';
		process->out2 = '0';
		process->output = temp->next->content;
	}
	else if (ft_strcmp(temp->content, ">>") == 0 && ft_check_out_access(process, temp->next) == 0)
	{
		process->out = '0';
		process->out2 = '1';
		process->output = temp->next->content;
	}
}

static int	ft_check_in_access(t_proc *process, t_mylist *temp)
{
	if (access(temp->content, F_OK) == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(temp->content, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		process->err = '1';
		return (1);
	}
	else if (access(temp->content, R_OK) == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(temp->content, STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
		process->err = '1';
		return (1);

	}
	return (0);
}
static int	ft_check_out_access(t_proc *process, t_mylist *temp)
{
	int fd; // repensar
	if (access(temp->content, F_OK) != -1 && access(temp->content, W_OK) == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(temp->content, STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
		process->err = '1';
		return (1);
	}
	else
	{
		fd = open(temp->content, O_CREAT, 0644);
		close(fd);
	}
	return (0);
}

/* static void	ft_error_redir(t_proc *process)
{

} */