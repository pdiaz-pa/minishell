/*
**	readline no reconoce las tabulaciones solo los espacios.
**	readline puede dar leaks segun el subject
**
*/

#include <stdio.h>
#include <readline/readline.h> // Compilar con -l readline
#include <stdlib.h> // Necesaria para free.

void	leaks()
{
	system("leaks a.out");
}

int main()
{
	atexit(leaks);

	char *buffer;

	while(buffer[0] != 'e' && buffer[1] != 'x' && buffer[2] != 'i' && buffer[3] != 't')
	{
		buffer = readline("Minishell$ "); //Devuelve la linea leida, recoge un str para mostrar por pantalla
		printf("%s\n", buffer); // Imprimimos la linea leida
		free(buffer); // Fundamental liberar cada linea leida por readline
	}
}