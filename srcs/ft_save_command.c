/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:01:40 by antgonza          #+#    #+#             */
/*   Updated: 2021/12/03 12:02:25 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_init_proc(t_proc *new);

void	ft_save_command(t_proc **proc,	t_mylist *tk_l)
{
	t_proc		*new;
	//t_mylist	*temp;

	if (tk_l){}

	new = malloc(sizeof (t_proc));
	if (new == NULL)
		perror("malloc error");
	ft_init_proc(new);

	if (*proc == NULL)
		*proc = new;
	/*else 
	{
	temp = *env;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	}*/
}

static void	ft_init_proc(t_proc *new)
{
	new->great = '0';
	new->great2 = '0';
	new->less = '0';
	new->less2 = '0';
	new->input = NULL;
	new->output = NULL;
}