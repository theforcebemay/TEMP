#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**create_square(int size)
{
	int		i;
	int		j;
	char	**square;

	i = 0;
	j = 0;
	if (!size)
		return (NULL);
	square = (char **)malloc(sizeof(char *) * size + 1);
	square[size] = NULL;
	if (!square)
		return (NULL);
	while (size >= i)
	{
		square[i] = (char *)malloc(sizeof(char) * size + 1);
		i++;
	}
	square[size][size] = '\0';
	i = 0;
	j = 0;
	while (square[i][j] != '\0')
	{
		if (square[i][j] != '\0')
		{
			square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (square);
}

int		main(void)
{
	int	i;
	char **sqr;
	i = 0;
	sqr = create_square(4);
	while (sqr[i])
		printf("%s\n", sqr[i++]);
	return (0);
}
