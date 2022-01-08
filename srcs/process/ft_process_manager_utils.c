/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_manager_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:28:24 by antgonza          #+#    #+#             */
/*   Updated: 2022/01/08 09:09:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_redir_in(t_proc *process)
{
	if (process->in == '1')
	{
		process->in_fd = open(process->input, O_RDONLY);
		if (process->in_fd == -1)
			exit(0);
		dup2(process->in_fd, STDIN_FILENO);
		close (process->in_fd);
	}
	else if (process->in2 == '1')
	{
		ft_heredoc(process);
		process->in_fd = open(".heredoc", O_RDONLY);
		dup2(process->in_fd, STDIN_FILENO);
		close (process->in_fd);
	}
	return ;
}

void	ft_redir_out(t_proc *process)
{
	if (process->out == '1')
	{
		process->out_fd = open(process->output, O_WRONLY | O_TRUNC, 0644);
		dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
	}
	else if (process->out2 == '1')
	{
		process->out_fd = open(process->output, O_WRONLY | O_APPEND, 0644);
		dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
	}
	return ;
}

void	ft_intermediate_redir(t_proc *process)
{
	close (process->fd[0]);
	if (process->input != NULL)
	{
		close(process->prev->fd[0]);
		ft_redir_in(process);
	}
	else
	{
		dup2(process->prev->fd[0], STDIN_FILENO);
		close(process->prev->fd[0]);
	}
	if (process->output != NULL)
	{
		close(process->fd[1]);
		ft_redir_out(process);
	}
	else
	{
		dup2(process->fd[1], STDOUT_FILENO);
		close(process->fd[1]);
	}
	return ;
}

void	ft_last_redir(t_proc *process)
{
	if (process->input != NULL)
	{
		close(process->prev->fd[0]);
		ft_redir_in(process);
	}
	else
	{
		dup2(process->prev->fd[0], STDIN_FILENO);
		close(process->prev->fd[0]);
	}
	return ;
}

void	ft_g_exit_status(int status)
{
	if (status == 2)
		g_exit_status = 130;
	if (status == 3)
		g_exit_status = 131;
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
}
