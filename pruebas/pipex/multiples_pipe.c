/*
 * 		** fork y pipe**
 *
 *	1. Pipe
 *		- Mecanismo IPC unidireccional.
 *		- Comunica procesos relacionados.
 *		- Envios de "byte streams"
 *		- pipe asociado a dos fd.
 *	2. Funciones
 *		- Crear pipe: int pipe(int fd[2]); fd[0] READ, fd[1] WRITE
 *		- Escritura: ssize_t write(int fd, const void, *buf, size_t nr);
 *		- Lectura: ssize_t read(int fd, void *buf, size_t nr);
 *		- Cerrar: int close(int fd);
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_fork(char *argv, int	*fd, int num)
{
	pid_t p1;  // Argumento para fork. 
	char buf[600]; // Aqui guardaremos lo leido del fd.
	int	n_read; // En esta variable guardamos los bytes leidos con read.

	p1 = fork(); // Creamos el proceso hijo.
	if (p1 == -1) // Si falla fork.
		printf("Error\n");
	else if (p1 > 0) // Se esta ejecutando el padre
	{
		close(fd[1]); // Cerramos el extremo de escritura del pipe.
		n_read = read(fd[0], buf, sizeof(buf) - 1); //Read no pone \0 
		close(fd[0]); // Una vez leido cerramos el fd.
		buf[n_read] = '\0'; // Importantisimo cerrar el str.
		printf("Se han leido %d bytes: %s\n",n_read, buf);
		exit(0);
	}
	else if (p1 == 0) //Se esta ejecutando el hijo
	{
		close(fd[0]); // Cerramos el extremo de lectura del pipe.
		write(fd[1], argv, 5); // Escribimos en el extremo de escritura.
		close(fd[1]); // Una vez escrito podemos cerrar el fd de escritura.
		exit(0);  // Terminamos el proceso hijo.
	}
}

void	ft_pipes(int total, char **argv)
{
	int i;
	int fd[total][2]; // Este fd se enviara como argumento a pipe.

	i = 0;
	while (i < total)
	{
		pipe(fd[i]);
		i++;
	}
	i = 0;
	while (i < total)
	{
		ft_fork(argv[i + 1], fd[i], i);
		i++;
	}


}

int main(int argc, char **argv)
{
	ft_pipes(argc - 1, argv);

	return (0);
}
