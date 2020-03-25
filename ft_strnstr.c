#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)str1;
	if (!ft_strlen(str2))
		return (ptr);
	i = 0;
	while (str1[i] && (i + ft_strlen(str2)) <= n)
	{
		if (*str2 == ptr[i])
		{
			if(!ft_strncmp(&ptr[i], str2, ft_strlen(str2)))
			{
				ptr = &ptr[i];
				return (ptr);
			}
		}
		i++;
	}
	return (NULL);
}