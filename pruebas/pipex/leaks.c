#include <string.h>
#include <stdlib.h>

/*
 *	Revisar leaks de FD abiertos
 *
 *	Evitar que termine el programa con un while(1){}
 *	En otra terminal ejecutamos lsof -c a.out
*/

void	sys_leaks()
{
	system("leaks a.out");
}

int	main()
{
	atexit(sys_leaks);
	char	*str;

	str = strdup("Hello leaks!");
}	
