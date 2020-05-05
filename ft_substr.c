/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:52:13 by pdemocri          #+#    #+#             */
/*   Updated: 2020/05/06 01:18:00 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] && i <= start)
		i++;
	if (start > i)
		return (str);
	i = 0;
	while (len > 0 && s[i])
	{
		str[i++] = s[start++];
		len--;
	}
	return (str);
}
