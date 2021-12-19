/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_manager_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:28:24 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/19 20:16:22 by antgonza         ###   ########.fr       */
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
		//ft_heredoc(process);
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
}