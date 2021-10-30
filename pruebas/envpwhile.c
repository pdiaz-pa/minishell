#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	int	i;

	while (1)
	{
		i = 0;
		while (envp[i])
		{
			printf("envp[%d] = %s\n", i, envp[i]);
			i++;
		}
		sleep(10);
	}
	return (0);
}
