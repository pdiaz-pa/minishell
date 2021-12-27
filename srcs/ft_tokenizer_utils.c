/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:09:03 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/12/27 16:31:14 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_last_spaces(char *prompt, t_tokenizer *tk)
{
	int	count;

	count = tk->start;
	while (prompt[count] != '\0')
	{
		if (prompt[count] != SPACE && prompt[count] != '\0')
			return (1);
		count++;
	}
	return (0);
}

int	ft_tk_delimiter(char *content)
{
	if (ft_strcmp(content, "|") == 0)
		return (1);
	else if (ft_strcmp(content, "<") == 0)
		return (2);
	else if (ft_strcmp(content, ">") == 0)
		return (2);
	else if (ft_strcmp(content, "<<") == 0)
		return (2);
	else if (ft_strcmp(content, ">>") == 0)
		return (2);
	else
		return (0);
}

int	ft_double_pipe(t_mylist *tk_l)
{
	if (ft_strcmp(tk_l->content, "|") == 0 && tk_l->next != NULL)
	{
		if (ft_strcmp(tk_l->next->content, "|") == 0)
			return (-1);
	}
	return (0);
}

void	ft_init_tk(t_tokenizer *tk)
{
	tk->size = 0;
	tk->sizer = 0;
	tk->start = 0;
	tk->single_flag = 0;
	tk->double_flag = 0;
	tk->expand = 0;
	tk->ch = 32;
}
