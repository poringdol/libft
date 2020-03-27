#include <string.h>
#include <stdlib.h>
#include "libft.h"


void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL && del != NULL)

	{
		t_list *tmp;
		while (*alst != NULL)
		{
			tmp = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
	        free(*alst);
	        *alst = tmp;
		}
	}
}