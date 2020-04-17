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
	buf[buf_size - 1] = '\0';
	while (buf_size > 0)
	{
		buf_size--;
		buf[buf_size] = '\0';
	}
	return ((void *)buf);
}