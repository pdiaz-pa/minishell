#include <stdio.h>
#include <readline/readline.h> // Compilar con -l readline

int main()
{
	char *buffer;

	while(buffer[0] != 'e' && buffer[1] != 'x' && buffer[2] != 'i' && buffer[3] != 't')
	{
		buffer = readline("Minishell$ "); //Devuelve la linea leida, recoge un str para mostrar por pantalla
		printf("%s\n", buffer); // Imprimimos la linea leida
	}
}