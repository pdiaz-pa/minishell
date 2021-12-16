#include "../includes/minishell.h"

t_mylist	*ft_mylstlast(t_mylist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_stack_printer(t_mylist *stack)
{
    stack = stack->next; // para que no se imprima el primer 0 (head)
    while(stack != NULL) // imprime cada nodo 
    {
        printf("%s->", stack->content);
        stack = stack->next;
    }
    printf("NULL\n");
}

void	ft_mylstadd_back(t_mylist **lst, t_mylist *new)
{
	t_mylist	*aux;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		aux = *lst;
		aux = ft_mylstlast(aux);
		aux->next = new;
	}
	return ;
}

char *ft_dollarizer(char *content)
{
	int i;

	i = 0;
	while (content[i] != '\0')
	{
		if (content[i] == '#')
			content[i] = '$';
		i++;
	}
	return(content);
}

t_mylist	*ft_mylstnew(void *content, int isexp)
{
	t_mylist	*new;

	new = malloc(sizeof(t_mylist));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->isexp = isexp;
	return (new);
}