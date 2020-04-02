#include <string.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int n;

	n = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}