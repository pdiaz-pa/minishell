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
	while (token[i] != SPACE && token[i] != '\0')
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
	key = ft_substr(token, (i - size), i);
	return (key);
}

void ft_expander(char *token, char *savedtk)
{
	int i;
	char *expanded;
	char *key;
	char *final;

	final = NULL;
	expanded = NULL;
	i = 0;
	while (token[i] != '\0' && token[i] != '$')
		i++;
	if (token[i] == '$')
	{
			key = ft_key_finder(token);
			final = ft_strcpy(final, ft_final_finder(final));
			savedtk = token;
			i = 0;
			while (token[i] != '$')
				i++;
			expanded = ft_substr(token, 0, i - 1);
			expanded = ft_strjoin(expanded, getenv(key));
			expanded = ft_strjoin(expanded, final);
	}
	printf("%s EXPANDED \n", expanded);
}