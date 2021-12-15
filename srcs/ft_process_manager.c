/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:59:54 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/15 21:48:14 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_process_manager(t_env *env, t_proc *process)
{
if (env){}
	if (process){}
}

void	ft_single_process(t_env *env, t_proc *process)
{
	if (env){}
	if (process){}
	int		or_fd[2];
	or_fd[0] = dup(STDIN_FILENO);
	or_fd[1] = dup(STDOUT_FILENO);

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
		
		//process->in_fd = open(process->input, O_RDONLY);
		/*if (process->in_fd == -1)
			exit(0);*/
		
		ft_heredoc(process);
		dup2(process->in_fd, STDIN_FILENO);
		close (process->in_fd);
	}
	if (process->out == '1')
	{
		process->out_fd = open(process->output, O_WRONLY | O_TRUNC, 0644);
		dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
	}
	else if (process->out2 == '1')
	{
		process->out_fd = open(process->output, O_WRONLY, 0644);
		dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
	}
	ft_prompt_cmp(env, process->list);
	dup2(or_fd[0], STDIN_FILENO);
	close(or_fd[0]);
	dup2(or_fd[1], STDIN_FILENO);
	close(or_fd[1]);
}