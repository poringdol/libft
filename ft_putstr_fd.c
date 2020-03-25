#include <string.h>
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	if (s == NULL)
		return;
	i = 0;
	while (s[i])
	{
		if (write(fd, &s[i], 1))
			i++;
	}
}
