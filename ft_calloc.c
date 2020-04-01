#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*buf;
	size_t	max_size;

	max_size = (FT_SIZE_MAX / size >= n) ? size * n : FT_SIZE_MAX;
	buf = (void *)malloc(max_size);
	if (buf == NULL)
		return (NULL);
	buf[max_size - 1] = '\0';
	while (max_size > 0)
	{
		max_size--;
		buf[max_size] = '\0';
	}	
	return ((void *)buf);
}
