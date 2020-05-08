/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:50:29 by pdemocri          #+#    #+#             */
<<<<<<< HEAD:sources/ft_strlcpy.c
/*   Updated: 2020/05/02 15:09:09 by pdemocri         ###   ########.fr       */
=======
/*   Updated: 2020/05/02 15:30:11 by pdemocri         ###   ########.fr       */
>>>>>>> defence:ft_strlcpy.c
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	unsigned int i;

	if (dst == NULL || src == NULL)
		return (0);
	if (n)
	{
		i = 0;
		while (src[i] && (i < n - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
