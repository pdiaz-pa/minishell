#include "../includes/minishell.h"

char *ft_final_finder(char *token)
{
	int i;
	int j;
	char *final;
	
	j = 0;
	i = 0;

	while (token[j] != '\0')
		j++;
	while (token[i] != '$')
		i++;
	
	while (token[i] != SPACE)
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
	while (token[i] != '$')
		i++;
	i++;
	while (token[i] != SPACE && token[i] != '\0')
	{
		i++;
		size++;
	}
	key = ft_substr(token, (i - size), size);
	return (key);
}

void	ft_expander(char *token, char *savedtk)
{
	int i;
	char *expanded;
	char *expkey;
	char *key;
	char *final;
	char *first;

	final = NULL;
	expanded = NULL;
	i = 0;
	while (token[i] != '\0' && token[i] != '$')
		i++;	
	if (token[i] == '$')
	{
			key = ft_key_finder(token);
			expkey = getenv(key);
			printf("%s KEY\n", key);
			printf("%s expKEY\n", expkey);
			final = ft_final_finder(token);
			printf("%s FINAL\n", final);
			savedtk = token;
			i = 0;
			while (token[i] != '$')
				i++;
			first = ft_substr(token, 0, i);
			printf("%sFIRST\n", first);
			expanded = ft_strjoin(first, expkey);
			expanded = ft_strjoin(expanded, final);
			printf("%s expanded\n", expanded);
	}
}