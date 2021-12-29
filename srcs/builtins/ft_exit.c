/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:49:21 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/29 08:52:32 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_env **env, t_cont *command)
{
	if (command){}
	ft_free_env(env);
	ft_putendl_fd("exit", 1);
	exit(exit_status);
}
