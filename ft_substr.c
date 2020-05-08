/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:52:13 by pdemocri          #+#    #+#             */
<<<<<<< HEAD:sources/ft_substr.c
/*   Updated: 2020/05/02 12:08:14 by pdemocri         ###   ########.fr       */
=======
/*   Updated: 2020/05/06 18:12:51 by pdemocri         ###   ########.fr       */
>>>>>>> defence:ft_substr.c
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	str = ft_calloc(len + 1, sizeof(char));
	if (s == NULL || str == NULL)
		return (NULL);
	i = 0;
<<<<<<< HEAD:sources/ft_substr.c
	while (s[i] && i <= start + len)
		i++;
	if (start > i)
		return (NULL);
=======
	while (s[i] && i <= start)
		i++;
	if (start > i)
	{
		if (!(str = (char *)ft_calloc(1, sizeof(char))))
			return (NULL);
		return (str);
	}
>>>>>>> defence:ft_substr.c
	i = 0;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (len > 0 && s[i])
	{
		str[i++] = s[start++];
		len--;
	}
	return (str);
}
