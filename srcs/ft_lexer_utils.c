/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:05:27 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/07 08:43:02 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_only_spaces(char *prompt)
{
	int	count;

	count = 0;
	while (prompt[count] != '\0')
	{
		if (prompt[count] != ' ' && prompt[count] != '\0')
			return (1);
		count++;
	}
	return (0);
}

void	ft_skip_spaces(char *prompt, t_tokenizer *tk)
{
	while (prompt[tk->start] == SPACE)
	{
		tk->start++;
		tk->sizer++;
	}	
}

int	ft_expandible(char *prompt, t_tokenizer *tk)
{
	if (prompt[tk->sizer + 1] != '\0'
		&& prompt[tk->sizer + 1] != DOUBLEQ
		&& prompt[tk->sizer] == '$'
		&& ((tk->double_flag == 1 && tk->single_flag == 0)
			|| (tk->double_flag == 0 && tk->single_flag == 0)))
		return (1);
	else
		return (0);
}

void	ft_flags(t_tokenizer *tk, char *prompt)
{
	if (tk->double_flag == 1 && prompt[tk->sizer] == DOUBLEQ)
		tk->double_flag = 0;
	else if (tk->double_flag == 0 && prompt[tk->sizer] == DOUBLEQ
		&& tk->single_flag == 0)
		tk->double_flag = 1;
	else if (tk->single_flag == 1 && prompt[tk->sizer] == SINGLEQ)
		tk->single_flag = 0;
	else if (tk->single_flag == 0 && prompt[tk->sizer] == SINGLEQ
		&& tk->double_flag == 0)
		tk->single_flag = 1;
}
