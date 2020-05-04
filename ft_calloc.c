/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:46:23 by pdemocri          #+#    #+#             */
/*   Updated: 2020/05/04 17:44:17 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*buf;
	size_t	buf_size;

	if (FT_SIZE_MAX / size < n)
		return (NULL);
	buf_size = size * n;
	buf = (void *)malloc(buf_size);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, buf_size);
	return ((void *)buf);
}
