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
	while (token[i] != SINGLEQ && token[i] != DOUBLEQ && token[i] != SPACE && token[i] != '\0')
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
	while (token[i] != SPACE && token[i] != '\0' && token[i] != '$' && token[i] != '#' && token[i] != DOUBLEQ && token[i] != SINGLEQ)
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

int ft_size_calc(char *str)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == SINGLEQ)
		{
			i++;
			while (str[i] != SINGLEQ && str[i] != '\0')
			{
				size++;
				i++;
			}
			if (str[i] == SINGLEQ)
				i++;
		}
		if (str[i] == DOUBLEQ)
		{
			i++;
			while (str[i] != DOUBLEQ && str[i] != '\0')
			{
				size++;
				i++;
			}
			if (str[i] == DOUBLEQ)
				i++;
		}
		if (str[i] != '\0' && str[i] != SINGLEQ && str[i] != DOUBLEQ)
		{
			i++;
			size++;
		}

	}
	return (size);
}

char *ft_dequoter(char *str, int size)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = 0;
	temp = malloc(size + 1);

	while (str[i] != '\0')
	{
		if (str[i] == SINGLEQ)
		{
			i++;
			while (str[i] != SINGLEQ && str[i] != '\0')
			{
				temp[j] = str[i];
				j++;
				i++;
			}
			if (str[i] == SINGLEQ)
				i++;
		}
		if (str[i] == DOUBLEQ)
		{
			i++;
			while (str[i] != DOUBLEQ && str[i] != '\0')
			{
				temp[j] = str[i];
				j++;
				i++;
			}
			if (str[i] == DOUBLEQ)
				i++;
		}
		if (str[i] != '\0' && str[i] != SINGLEQ && str[i] != DOUBLEQ)
		{
			temp[j] = str[i];
			j++;
			i++;
		}
	}
	temp[i] = '\0';
	return(temp);
}

char	*ft_quote_remover(char *str)
{
	int size;
	size = 0;
	size = ft_size_calc(str);
	str = ft_dequoter(str, size);
	//printf("%d el size\n", size);
	//printf("%s el str\n", str);
	return (str);
}

void	ft_expander(char *token, t_mylist *tk_l, t_env *env)
{
	int i;
	char *expanded;
	char *expkey;
	char *key;
	char *final;
	char *first;
	
	final = NULL;
	expanded = NULL;
	tk_l->nonexp = ft_strdup(tk_l->content); //leak!!!
	tk_l->nonexp = ft_dollarizer(tk_l->nonexp);
	tk_l->nonexp = ft_quote_remover(tk_l->nonexp);
	i = 0;
	while (ft_dollar_finder(tk_l->content) == 1)
	{
		while (tk_l->content[i] != '\0' && token[i] != '#')
			i++;	
			if (token[i] == '#')
			{
				key = ft_key_finder(tk_l->content);
				if (ft_strcmp(key, "?") == 0)
					ft_strcpy(tk_l->content, "INTERROGACIÓN");
				else
				{
					expkey = ft_get_my_env(key, env);
					//printf("%s KEY\n", key);
					//printf("%s expKEY\n", expkey);
					final = ft_final_finder(tk_l->content, i);
					//printf("%s FINAL\n", final);
					i = 0;
					while (tk_l->content[i] != '#')
						i++;
					first = ft_substr(tk_l->content, 0, i);
					//printf("%s FIRST\n", first);
					expanded = ft_strjoin(first, expkey); //leak!!
					expanded = ft_strjoin(expanded, final);
					free(final);
					free(first);
					free(key);
					free(expkey);
					tk_l->content = expanded;
					free(expanded);
				}
		}
	}
}