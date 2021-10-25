#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	char	*str;
	pid_t	pid;

	str = strdup("Malloc memory.");
	pid = fork();
	if (pid > 0)
	{
		printf("%d Padre 1 %p - %s\n", getpid(), str,str);
		free(str);
		str = strdup("Modificacion en padre");
		printf("%d Padre 2 %p - %s\n", getpid(), str,str);
	}
	else if (pid == 0)
	{
		printf("%d Hijo  %p - %s\n", getpid(), str,str);
	}
	else if (pid == -1)
		perror("Error");
	return (0);
}
