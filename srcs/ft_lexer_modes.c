/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_modes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 03:01:43 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/05 01:05:49 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_doubleq_mode(char *prompt, t_tokenizer *tk)
{
	int	size;

	size = 0;
	size++;
	tk->start++;
	while (prompt[tk->start] != DOUBLEQ && prompt[tk->start] != '\0')
	{
		if (prompt[tk->start] == '$')
			tk->expand = 0;
		tk->start++;
		size++;
	}
	if (prompt[tk->start] == DOUBLEQ)
	{
		tk->start++;
		size++;
	}
	return (size);
}

int	ft_singleq_mode(char *prompt, t_tokenizer *tk)
{
	int	size;

	tk->start++;
	size = 0;
	while (prompt[tk->start] != SINGLEQ && prompt[tk->start] != '\0')
	{
		if (prompt[tk->start] == '$')
			tk->expand = 1;
		tk->start++;
		size++;
	}
	if (prompt[tk->start] == SINGLEQ)
		tk->start++;
	return (size);
}

int	ft_normal_content(int size, char *prompt, t_tokenizer *tk)
{
	while (prompt[tk->start] != SPACE && prompt[tk->start] != '<'
		&& prompt[tk->start] != '>' && prompt[tk->start] != '|'
		&& prompt[tk->start] != '\0')
	{
		if (prompt[tk->start] != DOUBLEQ && prompt[tk->start] != SINGLEQ)
			size = ft_size_and_start(size, tk);
		else
		{
			if (prompt[tk->start] == SINGLEQ)
				size = size + (ft_singleq_mode(prompt, tk));
			if (prompt[tk->start] == DOUBLEQ)
				size = size + (ft_doubleq_mode(prompt, tk));
		}
	}
	if (prompt[tk->start] == SPACE || prompt[tk->start] == '\0')
		tk->size++;
	return (size);
}

int	ft_normal_mode(char *prompt, t_tokenizer *tk)
{
	int	size;

	size = 0;
	if (prompt[tk->start] == '|')
		size = ft_size_and_start(size, tk);
	else if (prompt[tk->start] == '<')
	{
		size = ft_size_and_start(size, tk);
		if (prompt[tk->start] == '<')
			size = ft_size_and_start(size, tk);
	}
	else if (prompt[tk->start] == '>')
	{
		size = ft_size_and_start(size, tk);
		if (prompt[tk->start] == '>')
			size = ft_size_and_start(size, tk);
	}
	else
		size = ft_normal_content(size, prompt, tk);
	return (size);
}
