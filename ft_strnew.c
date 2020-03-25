#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	max_size;

	max_size = (size < FT_SIZE_MAX) ? size + 1 : FT_SIZE_MAX;
	str = (char *)malloc((max_size) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[max_size - 1] = '\0';
	while (max_size > 0)
	{
		max_size--;
		str[max_size] = '\0';
	}
	return (str);
}