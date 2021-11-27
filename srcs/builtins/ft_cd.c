/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:10:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/11/26 18:41:38 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/* \
Primero necesito hacer env para actualizar PWD con el nuevo dir
 */
void	ft_cd(t_env **env, t_mylist *tk_l)
{
	t_env	*temp;
	char	ret;

	ret = '0';
	if (tk_l == NULL /* || (ft_strcmp(tk_l->content, "~")) == 0 */)
	{
		temp = ft_search_env(*env, "HOME");
		printf("\ntemp = %p\n", temp);
		if (temp == NULL)
		{
			printf("minishell: cd: HOME not set\n");
			ret = '1';
		}
		else
		{
			if((chdir(temp->line[1])) == -1)
			{
				printf("minishell: cd: %s: No such file or directory\n", temp->line[1]);
				ret = '1';
			}
		}
	}
	else 
	{
		if ((chdir(tk_l->content)) == -1)
		{
			printf("minishell: cd: %s: No such file or directory\n", tk_l->content);
			ret = '1';
		}
	}
	if (ret == '0')
	{}
	return ;
	/* temp = ft_search_env(env, "OLDPWD");
	temp2 = ft_search_env(env, "PWD");
	free (temp->line[1]);
	temp->line[1] = temp2->line[1];
	temp2->line[1] = ft_strdup(getcwd(NULL, 0)); */
}