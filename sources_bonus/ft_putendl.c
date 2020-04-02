#include <string.h>
#include <unistd.h>

void	ft_putendl(char const *s)
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
	if (!(write(1, "\n", 1)))
		return;
}
