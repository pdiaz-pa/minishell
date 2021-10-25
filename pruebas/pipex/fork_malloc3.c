#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	sl()
{
	system("leaks a.out");
}

int	main()
{
	atexit(sl);
	char	*str;
	pid_t	pid;

	str = strdup("Malloc memory.");
	pid = fork();
	if (pid > 0)
	{
		wait(0);
		printf("%d Padre 1 %p - %s\n", getpid(), str,str);
		free(str);  // Tenemos un leak en el proceso hijo liberar memoria en el padre no vale
		str = NULL;
	}
	else if (pid == 0)
	{
		printf("%d Hijo  %p - %s\n", getpid(), str,str);
	//	free(str);  // Liberar en el hijo sigue dando leak.
	//	str = NULL;
	}
	else if (pid == -1)
		perror("Error");
	return (0);
}
