#include <string.h>
#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst != NULL && *alst != NULL)
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}
