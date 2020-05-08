/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:49:56 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:03:49 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (i <= ft_strlen(ptr))
	{
		if (ptr[i] == (char)ch)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
