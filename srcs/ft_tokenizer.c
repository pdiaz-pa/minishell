/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:00:38 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/12/27 16:05:53 by pdiaz-pa         ###   ########.fr       */
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

int	ft_normal_mode(char *prompt, t_tokenizer *tk)
{
	int	size;

	size = 0;
	if (prompt[tk->start] == '|')
	{
		size++;
		tk->start++;
	}
	else if (prompt[tk->start] == '<')
	{
		size++;
		tk->start++;
		if (prompt[tk->start] == '<')
		{
			size++;
			tk->start++;
		}
	}
	else if (prompt[tk->start] == '>')
	{
		size++;
		tk->start++;
		if (prompt[tk->start] == '>')
		{
			size++;
			tk->start++;
		}	
	}
	else
	{
		while (prompt[tk->start] != SPACE && prompt[tk->start] != '<'
			&& prompt[tk->start] != '>' && prompt[tk->start] != '|'
			&& prompt[tk->start] != '\0')
		{
			if (prompt[tk->start] != DOUBLEQ && prompt[tk->start] != SINGLEQ)
			{
				size++;
				tk->start++;
			}
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
	}
	return (size);
}

int	ft_tk_recognizer(t_mylist *tk_l, t_env *env)
{
	int	i;

	i = 0;
	while (tk_l != NULL)
	{
		if (ft_tk_delimiter(tk_l->content) == 1)
			tk_l->tk_type = PIPE;
		else if (ft_tk_delimiter(tk_l->content) == 2)
			tk_l->tk_type = REDIR;
		else
			tk_l->tk_type = TEXT;
		ft_expander(tk_l->content, tk_l, env);
		tk_l->content = ft_quote_remover(tk_l->content);
		tk_l = tk_l->next;
		i++;
	}
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

int	ft_tk_creator(char *prompt, t_tokenizer *tk, t_mylist *token_list)
{
	int		j;
	char	*buff;

	buff = NULL;
	j = 0;
	while (prompt[tk->start] != '\0')
	{
		tk->expand = 0;
		while (prompt[tk->start] == SPACE)
		{
			tk->start++;
			tk->sizer++;
		}
		if (ft_last_spaces(prompt, tk) == 1)
		{
			ft_normal_mode(prompt, tk);
			buff = malloc((tk->start - tk->sizer) + 1);
			while (tk->sizer < tk->start)
			{
				ft_flags(tk, prompt);
				if (prompt[tk->sizer + 1] != '\0'
					&& prompt[tk->sizer + 1] != DOUBLEQ
					&& prompt[tk->sizer] == '$'
					&& ((tk->double_flag == 1 && tk->single_flag == 0)
						|| (tk->double_flag == 0 && tk->single_flag == 0)))
					buff[j] = '#';
				else
					buff[j] = prompt[tk->sizer];
				j++;
				tk->sizer++;
			}
			buff[j] = '\0';
			ft_mylstadd_back(&token_list, ft_mylstnew(buff, tk->expand));
			j = 0;
			free(buff);
		}
	}
	if (tk->double_flag == 1 || tk->single_flag == 1)
		return (-1);
	return (tk->size);
}

t_mylist	*ft_tokenizer(char *prompt, t_mylist *token_list, t_env *env)
{
	t_tokenizer	tk;

	ft_init_tk(&tk);
	token_list = ft_mylstnew("head", 0);
	if (ft_tk_creator(prompt, &tk, token_list) == -1)
	{
		printf("Error: Minishell does not support open quotes\n");
		token_list->isexp = -1;
	}
	else
	{
		if (ft_tk_recognizer(token_list->next, env) == -1)
		{
			printf("Error: Minishell does not support || \n");
			token_list->isexp = -1;
		}
	}
	return (token_list);
}
