/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:10:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/26 08:44:04 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/* \
Primero necesito hacer env para actualizar PWD con el nuevo dir
 */
void	ft_cd(t_env **env, t_mylist *tk_l)
{
	if (env){}
	if (tk_l){}
	
	/* int	i;
	t_env	*temp;
	t_env	*temp2;

	i = 0;
	if (argv[0] == 0 || argv[1] ==  '~')
	{
		temp = ft_search_env(env, "HOME");
		chdir(temp->line[1]);
	
	}
	argv++;
	chdir(argv);
	temp = ft_search_env(env, "OLDPWD");
	temp2 = ft_search_env(env, "PWD");
	free (temp->line[1]);
	temp->line[1] = temp2->line[1];
	temp2->line[1] = ft_strdup(getcwd(NULL, 0)); */
}