#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	char	**s1;
	s1 = (char **)malloc(sizeof(char *) * 5);
	while (i < 5)
		s1[i++] = (char *)malloc(sizeof(char) * 5);
	while (j < 5)
	{
		i = 0;
		while (i < 5)
			s1[j][i++] = i + '0';
		i = 0;
		j++;
	}
	j = 4;
	printf("%s\n%p\n -- BEFORE FREE\n", s1[1], s1);
	free(s1);
	printf("%s\n%p\n -- AFTER FREE\n", s1[1], s1);
	return (0);
}
