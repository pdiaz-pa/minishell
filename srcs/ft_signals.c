/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:30:32 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/07 07:43:05 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
