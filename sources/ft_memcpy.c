#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*dst_t;
	const unsigned char	*src_t;

	i = 0;
	dst_t = (unsigned char *)dst;
	src_t = (const unsigned char *)src;
	while (i < n && dst != src)
	{
		dst_t[i] = src_t[i];
		i++;
	}
	return (dst);
}
