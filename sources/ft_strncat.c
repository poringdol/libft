#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && j < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
