#include "../includes/minishell.h"


int ft_doubleq_mode(char *prompt, t_tokenizer *tk)
{
	int size;
	size = 0;
	tk->start++;
	//tk->sizer++;
	//tk->double_flag = 1;
	//printf("\e[0;31mMODO DOBLE\e[0m\n");
	while (prompt[tk->start] != 34 && prompt[tk->start] != '\0')
	{
		//printf("%c CHAR ", prompt[tk->start]);
		tk->start++;
		size++;
		//printf("%d START double\n", tk->start);
	}
	if (prompt[tk->start] == 34) 
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
	while (prompt[tk->start] != 39 && prompt[tk->start] != '\0')
	{
		//printf("%c CHAR ", prompt[tk->start]);
		tk->start++;
		size++;
		//printf("%d START single\n", tk->start);
	}
	if (prompt[tk->start] == 39)
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
	while(prompt[tk->start] != ' ' && prompt[tk->start] != '\0')
	{
		//printf("%c CHAR ", prompt[tk->start]);
		if (prompt[tk->start] != 34 && prompt[tk->start] != 39)
		{
			size++;
			tk->start++;
			//printf("%d START \n", tk->start);
		}
		else
		{
			if (prompt[tk->start] == 39)
				size = size + (ft_singleq_mode(prompt, tk));
			if (prompt[tk->start] == 34)
				size = size + (ft_doubleq_mode(prompt, tk));
		}	
	}
	//printf("%d SIZE DEL STRING\n", size);
	if (prompt[tk->start] == ' ' || prompt[tk->start] == '\0')
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
		if(prompt[count] != ' ' && prompt[count] != '\0')
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

int ft_str_size(char *prompt, t_tokenizer *tk, t_list *token_list)
{
	int j;
	char *buff;
	buff = NULL;
	j = 0;
	//printf("\e[42mCALCUATING *CHAR's SIZE...\e[0m\n");
	while (prompt[tk->start] != '\0')
	{
		while (prompt[tk->start] == ' ')
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
				if (tk->double_flag == 1 && prompt[tk->sizer] == 34)
				{
					tk->sizer++;
					tk->double_flag = 0;
				}
				else if (tk->double_flag == 0 && prompt[tk->sizer] == 34 && tk->single_flag == 0)
				{
					tk->sizer++;
					tk->double_flag = 1;
				}
				else if (tk->single_flag == 1 && prompt[tk->sizer] == 39)
				{
					tk->sizer++;
					tk->single_flag = 0;
				}
				else if (tk->single_flag == 0 && prompt[tk->sizer] == 39 && tk->double_flag == 0)
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
			ft_lstadd_back(&token_list, ft_lstnew(buff));
			//ft_stack_printer(token_list);
			j = 0;
			buff = NULL;
		}
	}
	//printf("\e[42m--------ENDED. TK->SIZE: \e[0m");
	//printf("\e[42m %d --------\e[0m\n\n", tk->size);
	return (tk->size);
}

void	ft_prompt_to_array(char *prompt, t_tokenizer *tk, t_list *token_list)
{
	//tk->size = ft_arr_size(prompt, tk); //comprobamos el tamaño del array con antelación para poder reservar la memoria suficiente
	ft_str_size(prompt, tk, token_list);
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

t_list *ft_tokenizer(char *prompt)
{
	t_list *token_list;
	t_tokenizer tk;

	ft_init_tk(&tk);
	token_list = ft_lstnew("head");
	ft_prompt_to_array(prompt, &tk, token_list);
	ft_stack_printer(token_list);
	token_list = NULL;
	return (token_list);
}
