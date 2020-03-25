#include <string.h>
#include "libft.h"

char *ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (i <= ft_strlen(ptr))
	{
		if (ptr[i] == (char)ch)
		{
			ptr = &ptr[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}