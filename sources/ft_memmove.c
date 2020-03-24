#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_t;
	unsigned char	*src_t;

	dst_t = (unsigned char *)dst;
	src_t = (unsigned char *)src;
	if (dst_t < src_t)
	{
		while (n)
		{
			*dst_t++ = *src_t++;
			n--;
		}
	}
	if (dst_t > src_t)
	{
		while (n)
		{
			n--;
			dst_t[n] = src_t[n];
		}
	}
	return (dst);
}