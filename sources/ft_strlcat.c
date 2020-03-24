#include "libft.h"
#define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

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
// # define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

// size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	dst_len;
// 	size_t	result_len;

// 	dst_len = ft_strlen(dst);
// 	result_len = FT_MIN(dstsize, dst_len) + ft_strlen(src);
// 	if (!(dstsize <= dst_len))
// 	{
// 		dst += dst_len;
// 		dstsize -= dst_len;
// 		while (*src && dstsize-- > 1)
// 			*dst++ = *src++;
// 		*dst = '\0';
// 	}
// 	return (result_len);
// }