#include "../includes/minishell.h"

void ft_stack_printer(t_mylist *stack)
{
    stack = stack->next; // para que no se imprima el primer 0 (head)
    while(stack != NULL) // imprime cada nodo 
    {
        printf("%s->", stack->token);
        stack = stack->next;
    }
    printf("NULL\n");
}

t_mylist *ft_init_t_stack(void)
{
    t_mylist *stack;
    stack = (t_mylist *)malloc(sizeof(t_mylist));
    stack->prev = NULL;
    stack->next = NULL;
    stack->token = NULL;

    return(stack);
}

void ft_make_list(t_mylist *head, char **token_arr, int array_size)
{
	int		idx;
	t_mylist	*new_node;

	idx = 0;
	while (idx < array_size)
	{
		new_node = (t_mylist *)malloc(sizeof(t_mylist));
    
		if (!new_node)
			printf("fuckyou");
		if (head->next == NULL)
		{
			new_node->token = token_arr[idx++];
			new_node->next = NULL;
			new_node->prev = head;
			head->next = new_node;
		}
		else
		{
			new_node->token = token_arr[idx++];
			new_node->next = head->next;
			new_node->next->prev = new_node;
			new_node->prev = head;
			head->next = new_node;
		}
	}
}

int ft_doubleq_mode(char *prompt, t_tokenizer *tk)
{
	int size;
	size = 0;
	tk->start++;
	//tk->sizer++;
	printf("\e[0;31mMODO DOBLE\e[0m\n");
	while (prompt[tk->start] != 34 && prompt[tk->start] != '\0')
	{
		printf("%c CHAR ", prompt[tk->start]);
		tk->start++;
		size++;
		printf("%d START double\n", tk->start);
	}
	if (prompt[tk->start] == 34) 
	{
		tk->start++;
		tk->sizer++;
	}
	return(size);
}

int ft_singleq_mode(char *prompt, t_tokenizer *tk)
{
	tk->start++;
	//tk->sizer++;
	int size;

	size = 0;
	printf("\e[0;33mMODO SINGLE\e[0m\n");
	while (prompt[tk->start] != 39 && prompt[tk->start] != '\0')
	{
		printf("%c CHAR ", prompt[tk->start]);
		tk->start++;
		size++;
		printf("%d START single\n", tk->start);
	}
	if (prompt[tk->start] == 39) 
	{
		tk->start++;
		tk->sizer++;
	}
	return(size);
}

int ft_normal_mode(char *prompt, t_tokenizer *tk)
{
	int size;
	size = 0;
	printf("\e[1;34mMODO NORMAL\e[0m\n");
	while(prompt[tk->start] != ' ' && prompt[tk->start] != '\0')
	{
		printf("%c CHAR ", prompt[tk->start]);
		if (prompt[tk->start] != 34 && prompt[tk->start] != 39)
		{
			size++;
			tk->start++;
			printf("%d START \n", tk->start);
		}
		else
		{
			if (prompt[tk->start] == 39)
			{
				size = size + (ft_singleq_mode(prompt, tk));
			}
			if (prompt[tk->start] == 34)
			{
				size = size + (ft_doubleq_mode(prompt, tk));
			}
		}	
	}
	printf("%d SIZE DEL STRING\n", size);
	if (prompt[tk->start] == ' ' || prompt[tk->start] == '\0')
	{
		tk->size++;
		printf("%d +1 SIZE NORMAL\n", tk->size);
		/*if(prompt[tk->start] == ' ')
		{
			tk->sizer++;
			tk->start++;
		}*/
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

int ft_arr_size(char *prompt, t_tokenizer *tk)
{
	tk->size = 0;
	printf("\e[46mCALCUATING ARRAY OF *CHAR's SIZE...\e[0m\n");
	while (prompt[tk->start] != '\0')
	{
		while (prompt[tk->start] == ' ' || prompt[tk->start] == 34)
		{
			tk->start++;
			tk->sizer++;
			printf("%d SKIPPING SPACE\n", tk->start);
		}
		if(ft_last_spaces(prompt, tk) == 1)
			ft_normal_mode(prompt, tk);	
	}
	printf("\e[46m--------ENDED. TK->SIZE: \e[0m");
	printf("\e[46m %d --------\e[0m\n\n", tk->size);
	return (tk->size);
}

int ft_str_size(char *prompt, t_tokenizer *tk)
{
	tk->size = 0;
	int str_size;
	int i;
	int j;
	j = 0;
	i = 0;
	str_size = 0;
	tk->start = 0;
	tk->sizer = 0;
	tk->double_flag = 0;
	tk->single_flag = 0;
	printf("\e[42mCALCUATING *CHAR's SIZE...\e[0m\n");
	while (prompt[tk->start] != '\0')
	{
		while (prompt[tk->start] == ' ')
		{
			tk->start++;
			tk->sizer++;
			printf("%d SKIPPING SPACE\n", tk->start);
		}
		if(ft_last_spaces(prompt, tk) == 1)
		{
			str_size = ft_normal_mode(prompt, tk);
			printf("%d STRING SIZE \n", str_size);
			tk->arr[i] = malloc(str_size);
			while (str_size > 0)
			{
				/*
				34-> "
				39-> '
				32-> SPACE
				*/
				printf("%d tkstart  %d  tksizer  %c\n", tk->start, tk->sizer, prompt[tk->sizer]);
				tk->arr[i][j] = prompt[tk->sizer];
				j++;
				tk->sizer++;
				str_size--;
			}
			tk->arr[i][j] = '\0';
			j = 0;
			printf("arr---->%s\n", tk->arr[i]);
			i++;
		}
	}
	printf("\e[42m--------ENDED. TK->SIZE: \e[0m");
	printf("\e[42m %d --------\e[0m\n\n", tk->size);
	return (tk->size);
}

char **ft_invert(char** arr, int n)
{
    char* temp;
	int i;
	int j;

	i = 0;
    j = n - 1;
    while (i < j) 
	{
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
		i++;
    }
	return(arr);
}

char **ft_prompt_to_array(char *prompt, t_tokenizer *tk)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tk->size = ft_arr_size(prompt, tk); //comprobamos el tamaño del array con antelación para poder reservar la memoria suficiente

	tk->arr = malloc(tk->size * sizeof(char *)); //reservamos memoria para el char ** pero también hay que alocar memoria para cada elemento, del tamaño del elemento que queremos alocar.
	ft_str_size(prompt, tk);
	tk->arr = ft_invert(tk->arr, tk->size);
	return(tk->arr);
}



t_mylist *ft_tokenizer(char *prompt)
{
	t_mylist *token_list;
	t_tokenizer tk;
	char **token_arr;
	int array_size;
	
	tk.size = 0;
	tk.sizer = 0;
	tk.start = 0;
	tk.single_flag = 0;
	tk.double_flag = 0;
	tk.ch = 32;
	array_size = 0;
	token_arr = ft_prompt_to_array(prompt, &tk);
	token_list = ft_init_t_stack();
	ft_make_list(token_list, token_arr, tk.size);
	ft_stack_printer(token_list);
	free(token_arr);
	return (token_list);
}
