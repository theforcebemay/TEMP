#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFSIZE 2048

typedef struct 		s_tetr {
	char			letter;
	struct s_tetr	*previous;
	struct s_tetr	*next;
	short int		xy[3];
}					t_tetr;

t_tetr	*create_list(char letter)
{
	t_tetr	*ret;
	ret = (t_tetr *)malloc(sizeof(t_tetr));
	if (!ret)
		return (NULL);
	ret->letter = letter;
	ret->next = NULL;
	ret->previous = NULL;
	return (ret);
}

void	lst_push_back(t_tetr *begin, t_tetr *new_list)
{
	t_tetr *temp;
	temp = begin;
	if (begin)
	{
		while (temp->next != NULL)
			temp = (t_tetr *)temp->next;
		temp->next = (struct s_tetr *)new_list;
		new_list->previous = (struct s_tetr *)temp;
		new_list->next = NULL;
	}
}

void	print_letters(t_tetr *start)
{
	if (start)
	{
		while (start != NULL)
		{
			printf("%c\n", start->letter);
			printf("%d\n", start->xy[0]);
			printf("%d\n", start->xy[1]);
			printf("%d\n", start->xy[2]);
			printf("%d\n", start->xy[3]);
			start = (t_tetr *)start->next;
		}
	}
}

void	print_reverse_list(t_tetr *go)
{
	t_tetr *temp;
	temp = go;

	if (go)
	{
		while (temp->next != NULL)
			temp = temp->next;
		while (temp != NULL)
		{
			printf("%c\n", temp->letter);
			temp = temp->previous;
		}
	}
}

void	free_list(t_tetr *go)
{
	t_tetr *temp;
	temp = go;

	if (go)
	{
		while (temp->next != NULL)
			temp = temp->next;
		while (temp != NULL)
		{
			free(temp->next);
			temp = temp->previous;
		}
		free(go);
	}
}
int		rows_passed(char *str, int i)
{
	int k;
	
	k = 0;
	while (i--)
	{
		if (*str++ == '#')
			k++;
	}
	return (k / 4);
}

t_tetr	*start_tear_apart(char *str, t_tetr *start, int size)
{
	short int 		i;
	int 			k;
	struct s_tetr	*ret;
	char			character;

	character = 'A';
	i = 0;
	k = 0;
	ret = create_list(character++);
	while (i < size)
	{
		if (str[i] == '#')
		{
			ret->xy[k] = i;
			k++;
		}
		if (k % 3 == 0)
		{
			lst_push_back(start, ret);
			return (start);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	buf[BUFSIZE];
	int		fd;
	int 	bts;
	t_tetr	*s;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	bts = read(fd, buf, BUFSIZE);
	if (bts == -1)
		return (0);
	printf("%d", rows_passed(buf, bts));
	s = start_tear_apart(buf, create_list('S'), 21);
	print_letters(s);	
	return (0);
}
/*	

int		main(void)
{
	t_tetr *go;
	go = create_list('a');
	lst_push_back(go, create_list('b'));
	lst_push_back(go, create_list('c'));
	lst_push_back(go, create_list('d'));
	lst_push_back(go, create_list('e'));
	lst_push_back(go, create_list('f'));
	lst_push_back(go, create_list('g'));
	lst_push_back(go, create_list('h'));
	print_letters(go);
	print_reverse_list(go);
	free_list(go);
	return (0);
}
*/
