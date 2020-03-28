#include "libft.h"

char	*ft_strlowcase(char *str)
{
	unsigned i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}