/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:00:38 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/06 02:39:15 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_tk_recognizer(t_mylist *tk_l, t_env *env)
{
	int		i;
	char	*temp;

	i = 0;
	while (tk_l != NULL)
	{
		if (ft_tk_delimiter(tk_l->content) == 1)
			tk_l->tk_type = PIPE;
		else if (ft_tk_delimiter(tk_l->content) == 2)
			tk_l->tk_type = REDIR;
		else
			tk_l->tk_type = TEXT;
		ft_expander(tk_l, env);
		temp = tk_l->content;
		tk_l->content = ft_quote_remover(tk_l->content, tk_l);
		free(temp);
		tk_l = tk_l->next;
		i++;
	}
	return (0);
}

void	ft_lexer(char *prompt, t_tokenizer *tk, t_mylist *token_list)
{
	int		j;
	char	*buff;

	tk->expand = 0;
	j = 0;
	ft_skip_spaces(prompt, tk);
	if (ft_last_spaces(prompt, tk) == 1)
	{
		ft_normal_mode(prompt, tk);
		buff = malloc((tk->start - tk->sizer) + 1);
		while (tk->sizer < tk->start)
		{
			ft_flags(tk, prompt);
			if (ft_expandible(prompt, tk) == 1)
				buff[j] = FKDOLLAR;
			else
				buff[j] = prompt[tk->sizer];
			j++;
			tk->sizer++;
		}
		buff[j] = '\0';
		ft_newtk(buff, tk, token_list);
	}
}

int	ft_tk_creator(char *prompt, t_tokenizer *tk, t_mylist *token_list)
{
	while (prompt[tk->start] != '\0')
	{
		ft_lexer(prompt, tk, token_list);
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
