/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:10:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/03 13:12:24 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/* \
Primero necesito hacer env para actualizar PWD con el nuevo dir
 */
void	ft_cd(char *argv, char **envp)
{
	int	i;

	i = 0;
	if (argv[0] == 0 || argv[1] ==  '~')
	{
		while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
			i++;
		chdir(&envp[i][5]);
	
	}
	argv++;
	chdir(argv);
}