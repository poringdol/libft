/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:50:21 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 11:50:23 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int length;
	unsigned int min;

	min = (ft_strlen(dst) < n) ? ft_strlen(dst) : n;
	length = min + ft_strlen(src);
	if (n == 0)
		return (length);
	i = 0;
	j = 0;
	i = ft_strlen(dst);
	while (src[j] && i < n - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (length);
}
