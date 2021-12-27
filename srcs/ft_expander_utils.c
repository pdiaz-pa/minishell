#include "../includes/minishell.h"

char *ft_final_finder(char *token, int i)
{
	int j;
	char *final;
	j = 0;

	while (token[j] != '\0')
		j++;
	while (token[i] != '#')
		i++;
	while (token[i] != SINGLEQ && token[i] != DOUBLEQ && token[i] != SPACE 
		&& token[i] != '\0')
		i++;
	final = ft_substr(token, i, j);
	return(final);
}

char *ft_key_finder(char *token)
{
	char *key;
	int i;
	int size;

	size = 0;
	i = 0;
	while (token[i] != '#')
		i++;
	i++;
	while (token[i] != SPACE && token[i] != '\0' && token[i] != '$' 
		&& token[i] != '#' && token[i] != DOUBLEQ && token[i] != SINGLEQ)
	{
		i++;
		size++;
	}
	key = ft_substr(token, (i - size), size);
	return (key);
}

int ft_dollar_finder(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '#')
			return(1);
		i++;
	}
	return(0);
}

char *ft_get_my_env(char *key, t_env *env)
{
	t_env *temp;
	char *expkey;
	
	expkey = NULL;
	temp = ft_search_env(env, key);
	if (temp != NULL)
		expkey = temp->line[1];
	return(expkey);
}

char	*ft_quote_remover(char *str)
{
	int size;
    char *temp;

	size = 0;
	size = ft_size_calc(str);
	temp = ft_dequoter(str, size);
	//printf("%d el size\n", size);
	//printf("%s el str\n", str);
	return (temp);
}
