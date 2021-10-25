/*
 * 		**procesos huerfanos y zombies**
 *
 * 		En este programa vamos a ejecutar dos procesos con un while y ir matando uno u otro
*/

#include <unistd.h> // Necesario para fork, getpid y sleep.
#include <stdio.h>  // Necesario para printf.

int	main()
{
	pid_t fork1;
	char  who[6];

	fork1 = fork();
	if (fork1 == -1)
		printf("Error en el fork\n");
	else if (fork1 > 0)
	{
		who[0] = 'p';
		who[1] = 'a';
		who[2] = 'd';
		who[3] = 'r';
		who[4] = 'e';
		who[5] = '\0';
	}
	else if (fork1 == 0)
	{
		who[0] = 'h';
		who[1] = 'i';
		who[2] = 'j';
		who[3] = 'o';
		who[4] = 0;
		who[5] = 0;	
	}
	while (1)
	{
		sleep (4);
		printf("PID %d Hola soy el proceso %s.\n", getpid(), who);
	}
	return (0);
}

/*
 * En este ejemplo vamos a ver en terminal los procesos en ejecucion y matar uno u otro.
 *
 * Los podemos ver mediente el comando ps que ya esta incluido en el sistema.
 * 		En linux ps -lf
 * Tambien los podemos en froma de arbol si instalamos pstree
 * 		brew install pstree
 *		pstree -s a.out
 * Ahora ejecutamos a.out en una terminal y en otra vemos los procesos activos.
 * Matamos uno u otro con el comando kill -9 numero de pid 
 *
 * Si matamos al proceso padre podemos ver que el hijo queda huerfano y es adoptado por el sistema
 * En el listado desaparece el PID del padre y en terminal avisa de la muerte de este.
 *
 * Si matamos el proceso hijo vemos que aunque deja de ejecutarse aun esta en memoria creando un zombie.
 * En el listado aun aparece el proceso hijo con su PID aunque no se este ejecutando y morira cuando
 * muera el padre.
*/
