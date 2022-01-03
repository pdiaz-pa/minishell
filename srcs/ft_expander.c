/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:08:51 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2022/01/03 06:42:05 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_size_calc(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == SINGLEQ)
		{
			i++;
			while (str[i] != SINGLEQ && str[i] != '\0')
			{
				size++;
				i++;
			}
			if (str[i] == SINGLEQ)
				i++;
		}
		if (str[i] == DOUBLEQ)
		{
			i++;
			while (str[i] != DOUBLEQ && str[i] != '\0')
			{
				size++;
				i++;
			}
			if (str[i] == DOUBLEQ)
				i++;
		}
		if (str[i] != '\0' && str[i] != SINGLEQ && str[i] != DOUBLEQ)
		{
			i++;
			size++;
		}
	}
	return (size);
}

char	*ft_dequoter(char *str, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc(size + 1);
	while (str[i] != '\0')
	{
		if (str[i] == SINGLEQ)
		{
			i++;
			while (str[i] != SINGLEQ && str[i] != '\0')
			{
				temp[j] = str[i];
				j++;
				i++;
			}
			if (str[i] == SINGLEQ)
				i++;
		}
		if (str[i] == DOUBLEQ)
		{
			i++;
			while (str[i] != DOUBLEQ && str[i] != '\0')
			{
				temp[j] = str[i];
				j++;
				i++;
			}
			if (str[i] == DOUBLEQ)
				i++;
		}
		if (str[i] != '\0' && str[i] != SINGLEQ && str[i] != DOUBLEQ)
		{
			temp[j] = str[i];
			j++;
			i++;
		}
	}
	temp[j] = '\0';
	return (temp);
}

void	ft_nonexp(t_mylist *tk_l)
{
	char	*temp;
	char	*temp2;

	temp = ft_strdup(tk_l->content);
	temp = ft_dollarizer(temp);
	temp2 = ft_quote_remover(temp);
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

void	ft_question_exp(char *temp, t_mylist *tk_l, char *key)
{
	temp = tk_l->content;
	tk_l->content = ft_itoa(exit_status);
	free(temp);
	free(key);
}

void	ft_expander(char *token, t_mylist *tk_l, t_env *env)
{
	int		i;
	char	*expanded;
	char	*expkey;
	char	*key;
	char	*final;
	char	*first;
	char	*temp;

	ft_nonexp(tk_l);
	final = NULL;
	expanded = NULL;
	i = 0;
	while (ft_dollar_finder(tk_l->content) == 1)
	{
		while (tk_l->content[i] != '\0' && token[i] != '#')
			i++;
		if (token[i] == '#')
		{
			key = ft_key_finder(tk_l->content);
			if (ft_strcmp(key, "?") == 0)
				ft_question_exp(temp, tk_l, key);
			else
			{
				expkey = ft_get_my_env(key, env);
				if (expkey == NULL)
					tk_l->tk_type = 3;
				final = ft_final_finder(tk_l->content, i);
				i = 0;
				while (tk_l->content[i] != '#')
					i++;
				first = ft_substr(tk_l->content, 0, i);
				temp = ft_strjoin(first, expkey);
				expanded = ft_strjoin(temp, final);
				ft_free_expander(first, final, key, temp);
				temp = tk_l->content;
				tk_l->content = expanded;
				free(temp);
			}
		}
	}
}
