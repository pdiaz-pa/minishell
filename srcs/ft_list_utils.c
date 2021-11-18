#include "../includes/minishell.h"
/*
void	ft_free_all(t_mylist *token_list, char **token_arr, t_tokenizer *tk)
{
	int i;

	i = 0;

	while (i != tk->size)
	{
		free(token_arr[i]);
		i++;
	}
	free(token_arr);
	ft_free_list(token_list);
}

void	ft_free_list(t_mylist *token_list)
{
	t_mylist	*ntoken;

	while (token_list)
	{
		ntoken = token_list->next;
		free(token_list);
		token_list->next = NULL;
		token_list->prev = NULL;
		token_list = ntoken;
	}
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
*/
void ft_stack_printer(t_list *stack)
{
    stack = stack->next; // para que no se imprima el primer 0 (head)
    while(stack != NULL) // imprime cada nodo 
    {
        printf("%s->", stack->content);
        stack = stack->next;
    }
    printf("NULL\n");
}