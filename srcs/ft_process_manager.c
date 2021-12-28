/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:59:54 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/28 08:43:05 by antgonza         ###   ########.fr       */
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
	unlink(".heredoc");
	dup2(or_fd[0], STDIN_FILENO);
	close(or_fd[0]);
	dup2(or_fd[1], STDOUT_FILENO);
	close(or_fd[1]);
	return ;
}

void	ft_single_process(t_env *env, t_proc *process)
{
	int		or_fd[2];

	or_fd[0] = dup(STDIN_FILENO);
	or_fd[1] = dup(STDOUT_FILENO);
	ft_redir_in(process);
	ft_redir_out(process);
	if (process->list != NULL && process->err == '0')
		exit_status = ft_prompt_cmp(env, process->list, 'a');
	unlink(".heredoc");
	dup2(or_fd[0], STDIN_FILENO);
	close(or_fd[0]);
	dup2(or_fd[1], STDOUT_FILENO);
	close(or_fd[1]);
	return ;
}

static void	ft_first_process(t_env *env, t_proc *process)
{
	ft_redir_in(process);
	pipe(process->fd);
	process->pid = fork();
	if (process->pid == 0)
	{
		close (process->fd[0]);
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
		if (process->list != NULL && process->err == '0')
			ft_prompt_cmp(env, process->list, 'b');
	}
	else
		close(process->fd[1]);
	return ;
}

static void	ft_intermediate_process(t_env *env, t_proc *process)
{
	pipe(process->fd);
	process->pid = fork();
	if (process->pid == 0)
	{
		ft_intermediate_redir(process);
		if (process->list != NULL && process->err == '0')
			ft_prompt_cmp(env, process->list, 'b');
	}
	else
	{
		close(process->prev->fd[0]);
		close(process->fd[1]);
	}
	return ;
}

static void	ft_last_process(t_env *env, t_proc *process)
{
	t_proc	*temp;

	temp = process;
	process->pid = fork();
	if (process->pid == 0)
	{
		ft_last_redir(process);
		ft_redir_out(process);
		if (process->list != NULL && process->err == '0')
			ft_prompt_cmp(env, process->list, 'b');
	}
	else
	{
		close(process->prev->fd[0]);
		while (temp->prev != NULL)
			temp = temp->prev;
		while (temp != NULL)
		{
			temp->pid = waitpid(temp->pid, &temp->ret, 0);
			temp = temp->next;
		}
		exit_status = process->ret;
	}
	return ;
}
