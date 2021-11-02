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

int ft_arr_size(char *prompt, int size, int start)
{
	while (prompt[start] != '\0')
	{
		if (prompt[start] == ' ')
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
	tk->size = ft_arr_size(prompt, tk->size, tk->start); //comprobamos el tamaño del array con antelación para poder reservar la memoria suficiente
	tk->start = 0;
	arr = malloc(tk->size * sizeof(char *)); //reservamos memoria para el char ** pero también hay que alocar memoria para cada elemento, del tamaño del elemento que queremos alocar.
	while (prompt[tk->sizer] != '\0')
	{
		while (prompt[tk->sizer] != ' ' && prompt[tk->sizer] != '\0') //calculamos el tamaño del string a guardar para reservar memoria en nuestro arr[i]
		{
			tk->sizer++;
		}
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
	array_size = 0;
	token_arr = ft_prompt_to_array(prompt, &tk);
	token_list = ft_init_t_stack();
	ft_make_list(token_list, token_arr, tk.size);
	ft_stack_printer(token_list);
	free(token_arr);
	return (token_list);
}
