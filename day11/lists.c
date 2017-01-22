#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			ft_putchar(*str);
}
		

t_list	*ft_create_elem(void *data)
{
	t_list	*ret;
		
	ret = (t_list *)malloc(sizeof(t_list));
	ret->data = data;
	ret->next = NULL;
	return (ret);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;
	
	list = *begin_list;	
	if (begin_list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *temp;

	if (!begin_list)
		*begin_list = ft_create_elem(data);
	else
		temp = ft_create_elem(data);
		temp->next = *begin_list;
		*begin_list = temp;
}

int		ft_list_size(t_list *begin_list)
{
	int i;
	
	i = 0;
	if (!begin_list)
		return (0);
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*temp;
	
	temp = begin_list;
	if (!begin_list)
		return (NULL);
	while (temp->next != NULL);
		temp = temp->next;
	return (temp);
}

int		main(void)
{
	char	s1[10] = "AAAA";
	char	s2[10] = "BBBB";
	char	s3[10] = "CCCC";
	char	s4[10] = "FRON";
	t_list *lst;

	lst = ft_create_elem(s1);
	ft_list_push_back(&lst, (void *)s2);
	ft_list_push_front(&lst, (void *)s4);
	ft_list_push_back(&lst, (void *)s3);
	lst = ft_list_last(lst);
	ft_putstr((char *)lst);
	free(lst);
	return (0);
}
