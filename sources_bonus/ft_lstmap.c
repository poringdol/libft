/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:32:26 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:33:23 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *fresh;
	t_list *res;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(fresh = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, fresh);
		lst = lst->next;
	}
	return (res);
}
