#include "libft.h"

char *ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*ptr;

	i = ft_strlen(str);
	ptr = (char *)str;
	while (i >= 0)
	{
		if (ptr[i] == (char)ch)
		{
			ptr = &ptr[i];
			return (ptr);
		}
		i--;
	}
	return (NULL);
}