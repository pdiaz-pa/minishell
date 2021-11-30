#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int ft_heredoc(char *str)
{
    char *keyword;
    int again;

    again = 1;
    while (again)
    {
        keyword = readline("> ");
        if (ft_strcmp(keyword, str) == 0)
            again = 0;
    }
    free(keyword);
    return(0);
}

int main()
{
    char test[5] = "hola\0";
    ft_heredoc(test);
    return(0);
}