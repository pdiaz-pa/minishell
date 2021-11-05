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
	if (promptchar == 32) // casos prompt espacio
	{
		if (tk->double_flag == 0 && tk->single_flag == 0)
			tk->ch = 32;
		else if (tk->double_flag == 1 && tk->single_flag == 0)
			tk->ch = 34;
		else if (tk->double_flag == 0 && tk->single_flag == 1)
			tk->ch = 39;
		else
			printf("SPACE: ERROR!!\n");
	}
	else if (promptchar == 34) // casos prompt doble
	{
		if (tk->double_flag == 0 && tk->single_flag == 0)
		{
			tk->double_flag = 1;
			tk->ch = 34;
		}

		else if (tk->double_flag == 1 && tk->single_flag == 0)
		{
			tk->double_flag = 0;
			tk->ch = 32;
		}

		else if (tk->double_flag == 0 && tk->single_flag == 1)
			tk->ch = 39;
		else
			printf("DOBLE: ERROR!!\n");
	}
	else if (promptchar == 39) // casos prompt simple
	{
		if (tk->double_flag == 0 && tk->single_flag == 0)
			tk->single_flag = 1;
		else if (tk->double_flag == 1 && tk->single_flag == 0)
			tk->ch = 34;
		else if (tk->double_flag == 0 && tk->single_flag == 1)
			tk->single_flag = 0;
		else
			printf("SIMPLE: ERROR!!\n");
	}
	else
	{
		if (tk->double_flag == 0 && tk->single_flag == 0)
			tk->ch = 32;
		else if (tk->double_flag == 1 && tk->single_flag == 0)
			tk->ch = 34;
		else if (tk->double_flag == 0 && tk->single_flag == 1)
			tk->ch = 39;
		else
			printf("OTROS: ERROR!!\n");
	}

	/*
	Casos posibles
	Caracter doubleflag singleflag action
	space		0			0		busca space, no cambia flags
	space		1			0		busca double, no cambia flags
	space		1			1		imposible
	space		0			1		busca single, no cambia flags
	double		0			0		busca double, cambia doubleflag
	double		1			0		busca space, cambia doubleflag
	double		1			1		imposible
	double		0			1		busca singleflag, no cambia flags
	single		0			0		busca single, cambia singleflag
	single		1			0		busca double, no cambia flags
	single		1			1		imposible
	single		0			1		busca space, cambia singleflag
	otro		0			0		busca space, no cambia flags
	otro		0			1		busca single, no cambia flags
	otro		1			0		busca double, no cambia flags
	otro		1			1		imposible
	*/
}
int ft_arr_size(char *prompt, int size, int start, t_tokenizer *tk)
{
	size = 1;
	while (prompt[start] != '\0')
	{
		ft_smart_token(prompt[start], tk);
		if (prompt[start] == tk->ch && tk->ch == ' ') //por cada espacio que encontramos en modo normal, +1 size
			size++;
		if (prompt[start] == tk->ch && tk->ch == 34) //por cada par de " que encontramos en modo ", +1 size
		{
			if (tk->double_flag % 2 == 0)
			{
				printf("encontré unas comillas dobles\n");
				size++;
			}
		}
        while (prompt[start] == ' ' && prompt[start] != '\0')
            start++;
        
		start++;
	}
	printf("%d -----SIZE-----\n", size);
	printf("-----------------\n");
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
		if (tk->ch == 34)
			ft_smart_token(prompt[tk->sizer], tk);
		if (prompt[tk->sizer] == tk->ch && tk->ch == 34 && tk->double_flag == 1)
			tk->sizer++;
		while (prompt[tk->sizer] != tk->ch && prompt[tk->sizer] != '\0') //calculamos el tamaño del string a guardar para reservar memoria en nuestro arr[i]
		{
			ft_smart_token(prompt[tk->sizer], tk);
			printf("%c SEPARADOR ", tk->ch);
			printf("%c promptchar \n", prompt[tk->sizer]);
			tk->sizer++;
		}
		if (prompt[tk->sizer] == tk->ch && tk->ch == 34 && tk->double_flag == 1)
			tk->sizer++;
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
		while(prompt[tk->sizer] == ' ' && prompt[tk->sizer] != '\0')
			tk->sizer++;
		tk->start = tk->sizer;
		i++;
	}
	return(arr);
}

t_mylist *ft_tokenizer2(char *prompt)
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
