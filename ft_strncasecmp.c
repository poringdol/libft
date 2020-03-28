#include <string.h>
#include "libft.h"

int     ft_strncasecmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n && (s1[i] || s2[i]))
		return (s1[i] - s2[i]);
	return (0);
}