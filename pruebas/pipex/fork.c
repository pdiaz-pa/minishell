/*
**			**fork(). Procesos padre e hijo**
**
**	pid_t fork(void)
**		- Crea un nuevo proceso "hijo".
**		- El proceso hijo es un duplicado del "padre".
**		- Los dos procesos:
**			- Tienen PIDs diferentes.
**			- Corren en espacios de memoria separados.
**	Retorno de fork()
**		- Si todo va bien:
**			- Retorno al padre: PID del hijo
**			- Retorno al hijo: 0
**		- Si hay errores:
**			- Retorno al padre: -1
**			- El hijo no es creado
*/

#include <unistd.h> // Necesario para las funciones fork y getpid.
#include <stdio.h>  // Necesario para la funcion printf.
#include <stdlib.h> // Necesario para la funcion exit().

int	main()
{
	pid_t fork1;

	printf("PID del proceso inicial \"padre\": %d\n\n", getpid());
	fork1 = fork(); // Llamamos a la funcion fork que creara un proceso hijo.
	// Este printf se ejecutara dos veces una por el padre y otra por el hijo.
	printf("PID ejecutandose: %d, fork1: %d\n", getpid(), fork1);
	if (fork1 == -1) // Error al crear fork
		printf("Error al crear fork.\n");
	else if (fork1 > 0) // Si se esta ejecutando el proceso padre
	{
		// Estas instrucciones solo son ejecutadas por el proceso padre.
		printf("Hola soy el proceso padre\n");
		exit (0); // Matamos el proceso padre.
	}
	else if (fork1 == 0) // Si se esta ejecutando el hijo
	{
		// Estas instrucciones son solo ejecutadas por el hijo.
		printf("Hola soy el proceso hijo\n");
		exit (0); // Matamos el proceso hijo.
	}
	// Este printf no se ejecutara si matamos los dos procesos.
	printf("Hola soy el proceso %d y aun estoy vivo\n", getpid());
	return (0);
}
