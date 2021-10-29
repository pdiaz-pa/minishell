#include "../includes/minishell.h"

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


char **ft_prompt_to_array(char *prompt)
{
	int i;
	int j;
	int size;
	char **arr;
	arr = NULL;
	i = 0;
	j = 0;
	size = 0;

	while (prompt[i] != '\0')
	{
		if(prompt[i] == ' ')
			size++;
		i++;
	}
	size++;
	arr = malloc(size * sizeof(char *)); //alocamos memoria para el char ** pero también hay que alocar memoria para cada elemento, del tamaño del elemento que queremos alocar.
	i = 0;
	j = 0;
	size = 0;
	while (prompt[i] != '\0')
	{
		while(prompt[i] != ' ')
		{

			i++;
			size++;
		}

		size = 0;
	}
	printf("%d size\n", size);
	return(arr);
}

t_mylist *ft_tokenizer(char *prompt)
{
	t_mylist *token_list;
	char **token_arr;
	int array_size;

	array_size = 0;
	token_arr = NULL;
	token_list = NULL;
	token_arr = ft_prompt_to_array(prompt);
	ft_make_list(token_list, token_arr, array_size);
	return (token_list);
}
