/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:59:54 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/17 11:52:36 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_first_process(t_env *env, t_proc *process);
static void	ft_intermediate_process(t_env *env, t_proc *process);
static void	ft_last_process(t_env *env, t_proc *process);

void	ft_process_manager(t_env *env, t_proc *process)
{
	int		or_fd[2];

	or_fd[0] = dup(STDIN_FILENO);
	or_fd[1] = dup(STDOUT_FILENO);
	if (process->num == 1)
		ft_first_process(env, process);
	else if (process->num < process->total)
		ft_intermediate_process(env, process);
	else if (process->num == process->total)
		ft_last_process(env, process);
	dup2(or_fd[0], STDIN_FILENO);
	close(or_fd[0]);
	dup2(or_fd[1], STDOUT_FILENO);
	close(or_fd[1]);
}

void	ft_single_process(t_env *env, t_proc *process)
{
	int		or_fd[2];

	or_fd[0] = dup(STDIN_FILENO);
	or_fd[1] = dup(STDOUT_FILENO);
	ft_redir_in(process);
	ft_redir_out(process);
	if (process->list != NULL)
		ft_prompt_cmp(env, process->list, 'a');
	//if (process->in2 == '1')
		unlink(".heredoc");
	dup2(or_fd[0], STDIN_FILENO);
	close(or_fd[0]);
	dup2(or_fd[1], STDOUT_FILENO);
	close(or_fd[1]);
}

static void	ft_first_process(t_env *env, t_proc *process)
{
	ft_redir_in(process);
	pipe(process->fd);
	process->pid = fork();
	if (process->pid == 0)
	{
		close (process->fd[0]);
		dup2(process->fd[1], STDOUT_FILENO);
		close(process->fd[1]);
		if (process->list != NULL)
			ft_prompt_cmp(env, process->list, 'b');
	}
	else
	{
		close(process->fd[1]);
		//process->pid = waitpid(-1, &process->ret, 0);
	}


}
static void	ft_intermediate_process(t_env *env, t_proc *process)
{
	pipe(process->fd);
	process->pid = fork();
	if (process->pid == 0)
	{
		close (process->fd[0]);
		dup2(process->prev->fd[0], STDIN_FILENO);
		close(process->prev->fd[0]);
		dup2(process->fd[1], STDOUT_FILENO);
		close(process->fd[1]);
		if (process->list != NULL)
			ft_prompt_cmp(env, process->list, 'b');
	}
	else
	{
		close(process->prev->fd[0]);
		close(process->fd[1]);
		//process->pid = waitpid(-1, &process->ret, 0);
	}

}
static void	ft_last_process(t_env *env, t_proc *process)
{
	int	i;

	i = 0;
	ft_redir_out(process);
	process->pid = fork();
	if (process->pid == 0)
	{
		dup2(process->prev->fd[0], STDIN_FILENO);
		close(process->prev->fd[0]);
		if (process->list != NULL)
			ft_prompt_cmp(env, process->list, 'b');
	}
	else
	{
		close(process->prev->fd[0]);
		while(i < process->total)
		{
		process->pid = waitpid(-1, &process->ret, 0);
		i++;
		}
	}
	
}