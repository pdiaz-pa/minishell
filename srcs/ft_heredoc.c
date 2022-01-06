/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:43:28 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/06 02:28:14 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_sig_int_here(int signal)
{
	(void)signal;
	printf("\n");
	exit(exit_status);
}

int	ft_pid_zero(int again, t_proc *process, int fd)
{
	char	*keyword;

	keyword = readline("> ");
	if (ft_strcmp(keyword, process->input) == 0)
		again = 0;
	else
	{
		write(fd, keyword, ft_strlen(keyword));
		write(fd, "\n", 1);
	}
	free(keyword);
	return (again);
}

int	ft_heredoc(t_proc *process)
{
	int		again;
	int		fd;
	pid_t	pid;

	pid = fork();
	signal(SIGINT, SIG_IGN);
	if (pid == -1)
		perror("pid error");
	else if (pid == 0)
	{
		again = 1;
		fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		signal(SIGINT, ft_sig_int_here);
		while (again)
			again = ft_pid_zero(again, process, fd);
		close (fd);
		exit(0);
	}
	else if (pid > 0)
		pid = waitpid(-1, NULL, 0);
	return (0);
}
