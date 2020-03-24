#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *str = s;
	while (n)
	{
		n--;
		str[n] = 0;
	}
}
