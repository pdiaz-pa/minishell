#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int	i;

	printf("argc = %d\n", argc);
	i = 0;
	while (i < argc)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (envp[i])
	{
		printf("envp[%d] = %s\n", i, envp[i]);
		i++;
	}
	return (0);	
}

