#include "libft.h"

size_t	ft_strlcpy (char *dst, const char *src, size_t n)
{
	unsigned int i;

	if (src == NULL)
		return (0);
	if (n && dst != NULL)
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