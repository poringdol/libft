#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	max_size;

	max_size = (size < SIZE_MAX) ? size + 1 : SIZE_MAX;
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