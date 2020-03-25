#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buf;
	size_t	max_size;

	max_size = (FT_SIZE_MAX / size >= n) ? size * n : FT_SIZE_MAX;
	buf = (void *)malloc(max_size);
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, 0, max_size);
	return (buf);
}