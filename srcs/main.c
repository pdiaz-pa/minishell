#include "minishell.h"

int	main()
{
	int again;
	char *name;

	again = 1;
	while (1)
	{
		while (again)
		{
			again = 0;
			name = readline("my_minishell$ ");
		}
	}
	return (0);
}