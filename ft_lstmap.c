#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *res;

	fresh = NULL;
	if (lst != NULL && f != NULL)
	{
		fresh = ft_lstnew(lst->content, sizeof(t_list));
		fresh = f(fresh);
		res = fresh;
	}
	while (lst->next != NULL && f != NULL)
	{
 		lst = lst->next;
		fresh->next = ft_lstnew(lst->content, sizeof(t_list));
		fresh->next = f(fresh->next);
		fresh = fresh->next;
	}
	return (res);
}