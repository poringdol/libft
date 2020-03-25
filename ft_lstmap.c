#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (lst != NULL && f != NULL)
	{
		return (lst);
	}
	return (lst);
}