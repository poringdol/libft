#include "libft.h"

char	*ft_strupcase(char *str)
{
	unsigned i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}