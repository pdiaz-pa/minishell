#include "../includes/minishell.h"

void ft_stack_printer(t_mylist *stack)
{
    stack = stack->next; // para que no se imprima el primer 0 (head)
    while(stack) // imprime cada nodo 
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

void ft_smart_token(char promptchar, t_tokenizer *tk)
{
	/*
		34-> "
		39-> '
		32-> SPACE
	*/
	printf("%c promptchar\n", promptchar);
	if ((promptchar == 34) && tk->single_flag == 0) //si encontramos un " buscamos un ", activamos flag
	{
		tk->ch = 34;
		tk->double_flag = 1;
		printf("buscando DOUBLE\n");
	}
	else if ((promptchar == 39) && tk->double_flag == 0) //si encontramos un ' buscamos un ' activamos flag
	{
		tk->ch = 39;
		tk->single_flag = 1;
		printf("buscando SINGLE\n");
	}
	else if ((promptchar == 34) && tk->double_flag == 1) //si encontramos un segundo " buscamos un ' ' desactivamos flag
	{
		tk->ch = 32;
		tk->double_flag = 0;
		printf("buscando SPACE TRAS CERRAR  DOUBLE\n");
	}
	else if ((promptchar == 39) && tk->single_flag == 1) //si encontramos un segundo ' buscamos un ' ' desactivamos flag
	{
		tk->ch = 32;
		tk->single_flag = 0;
		printf("buscando SPACE TRAS CERRAR SINGLE\n");
	}
	else
	{
		if(tk->double_flag == 0 && tk->single_flag == 0)
		tk->ch = 32;
		printf("buscando SPACE\n");
	}

	
}
int ft_arr_size(char *prompt, int size, int start, t_tokenizer *tk)
{
	while (prompt[start] != '\0')
	{
		ft_smart_token(prompt[start], tk);
		if (prompt[start] == tk->ch)
		{
			size++;
		}
		start++;
	}
	size++;
	return(size);
}

char **ft_prompt_to_array(char *prompt, t_tokenizer *tk)
{
	int i;
	int j;
	char **arr; //aquí almacenaremos temporalmente nuestros tokens
	arr = NULL;
	i = 0;
	j = 0;
	tk->size = ft_arr_size(prompt, tk->size, tk->start, tk); //comprobamos el tamaño del array con antelación para poder reservar la memoria suficiente
	tk->start = 0;
	arr = malloc(tk->size * sizeof(char *)); //reservamos memoria para el char ** pero también hay que alocar memoria para cada elemento, del tamaño del elemento que queremos alocar.
	while (prompt[tk->sizer] != '\0')
	{
		while (prompt[tk->sizer] != tk->ch && prompt[tk->sizer] != '\0') //calculamos el tamaño del string a guardar para reservar memoria en nuestro arr[i]
		{
			ft_smart_token(prompt[tk->sizer], tk);
			tk->sizer++;
		}
		printf("%d SIZER\n", (tk->sizer - tk->start));
		arr[i] = malloc(((tk->sizer - tk->start) * sizeof(char)) + 1); //reservamos la memoria de sizer + 1 para el '\0'
		while(tk->start != tk->sizer) //copiamos caracter a caracter el string en nuestro array
		{
			arr[i][j] = prompt[tk->start];
			j++;
			tk->start++;
		}
		arr[i][j] = '\0';
		j = 0;
		printf("%s array \n", arr[i]);
		while(prompt[tk->sizer] == ' ')
			tk->sizer++;
		tk->start = tk->sizer;
		i++;
	}
	return(arr);
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
