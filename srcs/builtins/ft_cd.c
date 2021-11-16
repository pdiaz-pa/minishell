/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:10:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/16 14:57:23 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/* \
Primero necesito hacer env para actualizar PWD con el nuevo dir
 */
void	ft_cd(char *argv, t_env *env)
{
	int	i;
	t_env	*temp;
	t_env	*temp2;
	if (argv[0])
		argv++;
	if (argv[0])
		argv++;
	i = 0;
	if (argv[0] == 0 || argv[0] ==  '~')
	{
		temp = search_env(env, "HOME");
		chdir(temp->line[1]);
	
	}
	if (chdir(argv) == -1)
		perror("chdir error");
	else
	{
	temp = search_env(env, "OLDPWD");
	temp2 = search_env(env, "PWD");
	free (temp->line[1]);
	temp->line[1] = temp2->line[1];
	temp2->line[1] = getcwd(NULL, 0);
	}
}