#include <string.h>
#include "libft.h"
#include "libft_bonus.h"

char	*ft_strcasestr(const char *str1, const char *str2)
{
	int i;
	int len;
	char *ptr;

	ptr = (char *)str1;
	len = ft_strlen(str2);
	if (!len)
		return (ptr);
	i = 0;
	while (str1[i])
	{
		if (ft_tolower(*str2) == ft_tolower(ptr[i]))
		{
			if(!ft_strncasecmp(&ptr[i], str2, len))
			{
				ptr = &ptr[i];
				return (ptr);
			}
		}
		i++;
	}
	return (NULL);
}
