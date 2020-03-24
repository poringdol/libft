#include "libft.h"

void	ft_putstr(char const *s)
{
	int i;

	if (s == NULL)
		return;
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1))
			i++;
	}
}