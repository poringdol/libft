#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *fresh;
	t_list *res;

	fresh = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(fresh = ft_lstnew(lst->content)))
		return (NULL);
	fresh = f(fresh);
	res = fresh;
	while (lst->next != NULL)
	{
 		lst = lst->next;
		if (!(fresh->next = ft_lstnew(lst->content)))
			return (NULL);
		fresh->next = f(fresh->next);
		fresh = fresh->next;
	}
	del(fresh);
	return (res);
}