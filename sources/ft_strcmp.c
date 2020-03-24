#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;
	const unsigned char *s1;
	const unsigned char *s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}