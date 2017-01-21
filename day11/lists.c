#include "header.h"

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
	if (begin_list)
	{
		i++;
		ft_list_size(begin_list->next);
	}
	else
		return (i);
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
	printf("%d\n", ft_list_size(lst));
	while (lst)
	{
		printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}
	free(lst);
	return (0);
}
