#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		c_t;
	unsigned char		*dst_t;
	unsigned const char	*src_t;

	i = 0;
	c_t = (unsigned char)c;
	dst_t = (unsigned char *)dst;
	src_t = (unsigned const char *)src;
	while (i < n)
	{
		if (src_t[i] == c_t)
		{
			dst_t[i] = src_t[i];
			i++;
			return (&dst_t[i]);
		}
		dst_t[i] = src_t[i];
		i++;
	}
	return (NULL);
}