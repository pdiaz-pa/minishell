#include <stdio.h>
#include <string.h>

int	main()
{
	printf("dif A y Z = %d\n", strcmp("A", "Z"));
	printf("dif Z y A = %d\n", strcmp("Z", "A"));
	printf("dif A y NULL = %d\n", strcmp("A", NULL));
	printf("dif NULL y NULL = %d\n", strcmp(NULL, NULL));
}