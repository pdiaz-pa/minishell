/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:59:54 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/14 12:38:59 by antgonza         ###   ########.fr       */
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

	}
	if (process->out == '1')
	{
		process->out_fd = open(process->output, O_WRONLY | O_TRUNC);
		dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
	}
	else if (process->out2 == '1')
	{
		process->out_fd = open(process->output, O_WRONLY);
		dup2(process->out_fd, STDOUT_FILENO);
		close(process->out_fd);
	}
	ft_prompt_cmp(env, process->list);
}