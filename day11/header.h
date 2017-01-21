#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef HEADER_H
# define HEADER_H

typedef struct 		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif
