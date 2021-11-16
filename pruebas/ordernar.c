#include <stdio.h>


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int argc, char **argv)
{
	int dif;

	dif = ft_strcmp(argv[1], argv[2]);
	printf ("diferencia = %d\n", dif);
	if (dif < 0)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", argv[2]);
	}
	else
	{
		printf("%s\n", argv[2]);
		printf("%s\n", argv[1]);
	}

}