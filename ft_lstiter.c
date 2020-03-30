#include <string.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && f != NULL)
	{
		t_list *tmp = lst;
		f(lst);
		lst = tmp->next;
	}
}
