/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:00:38 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/11/26 12:13:29 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_doubleq_mode(char *prompt, t_tokenizer *tk)
{
	int size;
	size = 0;
	tk->start++;
	//tk->sizer++;
	//tk->double_flag = 1;
	//printf("\e[0;31mMODO DOBLE\e[0m\n");
	while (prompt[tk->start] != DOUBLEQ && prompt[tk->start] != '\0')
	{
		//printf("%c CHAR ", prompt[tk->start]);
		tk->start++;
		size++;
		//printf("%d START double\n", tk->start);
	}
	if (prompt[tk->start] == DOUBLEQ) 
	{
		tk->start++;
		//tk->sizer++;		
	}
	return(size);
}

int ft_singleq_mode(char *prompt, t_tokenizer *tk)
{
	tk->start++;
	//tk->sizer++;	
	tk->sizer++;
	int size;

	size = 0;
	//printf("\e[0;33mMODO SINGLE\e[0m\n");
	tk->single_flag = 1;
	while (prompt[tk->start] != SINGLEQ && prompt[tk->start] != '\0')
	{
		//printf("%c CHAR ", prompt[tk->start]);
		tk->start++;
		size++;
		//printf("%d START single\n", tk->start);
	}
	if (prompt[tk->start] == SINGLEQ)
	{
		tk->start++;
		//tk->sizer++;
	}
	return(size);
}

int ft_normal_mode(char *prompt, t_tokenizer *tk)
{
	int size;
	size = 0;
	//printf("\e[1;34mMODO NORMAL\e[0m\n");
	while(prompt[tk->start] != SPACE && prompt[tk->start] != '\0')
	{
		//printf("%c CHAR ", prompt[tk->start]);
		if (prompt[tk->start] != DOUBLEQ && prompt[tk->start] != SINGLEQ)
		{
			size++;
			tk->start++;
			//printf("%d START \n", tk->start);
		}
		else
		{
			if (prompt[tk->start] == SINGLEQ)
				size = size + (ft_singleq_mode(prompt, tk));
			if (prompt[tk->start] == DOUBLEQ)
				size = size + (ft_doubleq_mode(prompt, tk));
		}	
	}
	//printf("%d SIZE DEL STRING\n", size);
	if (prompt[tk->start] == SPACE || prompt[tk->start] == '\0')
	{
		tk->size++;
		//printf("%d +1 SIZE NORMAL\n", tk->size);
	}
	return (size);
}

int ft_last_spaces(char *prompt, t_tokenizer *tk)
{
	int count;

	count = tk->start;
	while (prompt[count] != '\0')
	{
		if(prompt[count] != SPACE && prompt[count] != '\0')
			return(1);
		count++;
	}
	return(0);
}
	/*
	34-> "
	39-> '
	32-> SPACE
	*/

int ft_tk_delimiter(char *content)
{
	if (ft_strcmp(content, "|") == 0)
		return(1);
	else if (ft_strcmp(content, "<") == 0)
		return(1);
	else if (ft_strcmp(content, ">") == 0)
		return(1);
	else if (ft_strcmp(content, "<<") == 0)
		return(1);
	else if (ft_strcmp(content, ">>") == 0)
		return(1);
	else
		return(0);
}

void ft_tk_recognizer(t_mylist *tk_l)
{
	while (tk_l != NULL)
	{
		printf("%s ", tk_l->content);
		if (ft_tk_delimiter(tk_l->content) == 1)
		{
			tk_l->tk_type = DELIMITER;
			printf("tipo DELIMITER\n");
		}
		else
		{
			tk_l->tk_type = TEXT;
			printf("tipo TEXT\n");
		}
		ft_expander(tk_l->content, tk_l->exp, tk_l);
		tk_l = tk_l->next;
	}
}

int ft_tk_creator(char *prompt, t_tokenizer *tk, t_mylist *token_list)
{
	int j;
	char *buff;
	buff = NULL;
	j = 0;
	//printf("\e[42mCALCUATING *CHAR's SIZE...\e[0m\n");
	while (prompt[tk->start] != '\0')
	{
		while (prompt[tk->start] == SPACE)
		{
			tk->start++;
			tk->sizer++;
			//printf("%d SKIPPING SPACE\n", tk->start);
		}
		if(ft_last_spaces(prompt, tk) == 1)
		{
			ft_normal_mode(prompt, tk);
			//printf("%d STRING SIZE \n", (tk->start - tk->sizer));
			buff = malloc((tk->start - tk->sizer) + 1);
			while (tk->sizer < tk->start)
			{
				//printf("%d tkstart  %d  tksizer  %c\n", tk->start, tk->sizer, prompt[tk->sizer]);
				if (tk->double_flag == 1 && prompt[tk->sizer] == DOUBLEQ)
				{
					tk->sizer++;
					tk->double_flag = 0;
				}
				else if (tk->double_flag == 0 && prompt[tk->sizer] == DOUBLEQ && tk->single_flag == 0)
				{
					tk->sizer++;
					tk->double_flag = 1;
				}
				else if (tk->single_flag == 1 && prompt[tk->sizer] == SINGLEQ)
				{
					tk->sizer++;
					tk->single_flag = 0;
				}
				else if (tk->single_flag == 0 && prompt[tk->sizer] == SINGLEQ && tk->double_flag == 0)
				{
					tk->sizer++;
					tk->single_flag = 1;
				}
				else
				{
					buff[j] = prompt[tk->sizer];
					j++;
					tk->sizer++;
				}

			}
			buff[j] = '\0';
			//printf("buffer---->%s\n", buff);
			ft_mylstadd_back(&token_list, ft_mylstnew(buff));
			//ft_stack_printer(token_list);
			j = 0;
			buff = NULL;
		}
	}
	//printf("\e[42m--------ENDED. TK->SIZE: \e[0m");
	//printf("\e[42m %d --------\e[0m\n\n", tk->size);
	ft_tk_recognizer(token_list->next);
	return (tk->size);
}

void ft_init_tk(t_tokenizer *tk)
{
	tk->size = 0;
	tk->sizer = 0;
	tk->start = 0;
	tk->single_flag = 0;
	tk->double_flag = 0;
	tk->ch = 32;
}

t_mylist *ft_tokenizer(char *prompt, t_mylist *token_list)
{
	t_tokenizer tk;

	ft_init_tk(&tk);
	token_list = ft_mylstnew("head");
	ft_tk_creator(prompt, &tk, token_list);
	return (token_list);
}
