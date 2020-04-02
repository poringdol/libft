#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	char *str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start + len > i)
		return (NULL);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	return (str);
}
