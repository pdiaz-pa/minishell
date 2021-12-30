/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 08:38:12 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/30 14:45:37 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_check_points(char *check);

int	ft_is_dir(char *check, char mode)
{
	struct stat	info;
	int			ret;
	
	ret = ft_check_points(check);
	if (ret > 0)
		return (ret);
	if (lstat(check, &info) == 0)
	{
		if (S_ISDIR(info.st_mode))
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(check, STDERR_FILENO);
			if (mode == 'a')
			{
				ft_putendl_fd(": Is a directory", STDERR_FILENO);
				return (1);
			}
			else if (mode == 'b')
			{
				ft_putendl_fd(": is a directory", STDERR_FILENO);
				return (126);
			}
		}
	}
	return (0);
}

static int	ft_check_points(char *check)
{
	if (ft_strcmp(check, ".") == 0 || ft_strcmp(check, "..") == 0)
	{
		if (ft_strcmp(check, ".") == 0)
		{
			ft_putendl_fd("minishell: .: usage: . filename [arguments]",
				STDERR_FILENO);
			return (2);
		}
		else if (ft_strcmp(check, "..") == 0)
		{
			ft_putendl_fd("minishell: ..: command not found", STDERR_FILENO);
			return (127);
		}
	}
	return (0);
}
