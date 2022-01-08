/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:30:32 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/08 09:09:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_signal_handle(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ft_sig_int);
}

void	backup_termattr(struct termios *termattr)
{
	static int	flag;

	if (flag)
		return ;
	tcgetattr(STDOUT_FILENO, termattr);
	flag = 1;
}

void	reset_termattr(struct termios *termattr)
{
	tcsetattr(STDOUT_FILENO, TCSANOW, termattr);
}

void	turnoff_echoctl_termattr(void)
{
	struct termios	termattr;

	tcgetattr(STDOUT_FILENO, &termattr);
	termattr.c_lflag = ~(ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &termattr);
}

void	ft_sig_int(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_exit_status = 1;
	}
}
