#include <string.h>
#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst != NULL && *alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (alst != NULL && *alst == NULL && new != NULL)
		*alst = new;
}