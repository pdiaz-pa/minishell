#include <string.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	char	*str;
	pid_t	pid;

	str = strdup("Malloc memory.");
	pid = fork();
	if (pid > 0)
		printf("%d Padre %p\n", getpid(), str);
	else if (pid == 0)
		printf("%d Hijo  %p\n", getpid(), str);
	else if (pid == -1)
		perror("Error");
	return (0);
}
