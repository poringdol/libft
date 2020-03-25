#include <string.h>
#include <stdlib.h>
#include "libft.h"


void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL)
		return ;
	return ;
}