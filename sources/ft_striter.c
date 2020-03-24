#include "libft.h"

void ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = 0;
	if (s == NULL)
		return;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}