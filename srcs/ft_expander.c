/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:08:51 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/08 09:09:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_nonexp(t_mylist *tk_l)
{
	char	*temp;
	char	*temp2;

	temp = ft_strdup(tk_l->content);
	temp = ft_dollarizer(temp);
	temp2 = ft_quote_remover(temp, tk_l);
	free(temp);
	tk_l->nonexp = ft_strdup(temp2);
	free(temp2);
}

void	ft_free_expander(char *first, char *final, char *key, char *temp)
{
	free(temp);
	temp = NULL;
	free(final);
	final = NULL;
	free(first);
	first = NULL;
	free(key);
	key = NULL;
}

void	ft_question_exp(t_mylist *tk_l, char *key)
{
	char	*temp;

	temp = tk_l->content;
	tk_l->content = ft_itoa(g_exit_status);
	free(temp);
	free(key);
}

void	ft_normal_exp(t_mylist *tk_l, char *key, t_env *env)
{
	char	*temp;
	char	*expkey;
	char	*final;
	char	*first;
	char	*expanded;

	final = NULL;
	expanded = NULL;
	expkey = ft_get_my_env(key, env);
	if (expkey == NULL)
		tk_l->tk_type = 3;
	tk_l->i++;
	final = ft_final_finder(tk_l->content, tk_l->i);
	tk_l->i = 0;
	while (tk_l->content[tk_l->i] != FKDOLLAR)
		tk_l->i++;
	first = ft_substr(tk_l->content, 0, tk_l->i);
	temp = ft_strjoin(first, expkey);
	expanded = ft_strjoin(temp, final);
	ft_free_expander(first, final, key, temp);
	temp = tk_l->content;
	tk_l->content = expanded;
	free(temp);
}

void	ft_expander(t_mylist *tk_l, t_env *env)
{
	char	*key;

	ft_nonexp(tk_l);
	tk_l->i = 0;
	while (ft_dollar_finder(tk_l->content) == 1)
	{
		while (tk_l->content[tk_l->i] != '\0'
			&& tk_l->content[tk_l->i] != FKDOLLAR)
			tk_l->i++;
		if (tk_l->content[tk_l->i] == FKDOLLAR)
		{
			key = ft_key_finder(tk_l->content);
			if (ft_strcmp(key, "?") == 0)
				ft_question_exp(tk_l, key);
			else
				ft_normal_exp(tk_l, key, env);
		}
	}
}
