#include <string.h>
#include <unistd.h>

void ft_putendl_fd(char const *s, int fd)
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
	if (!(write(fd, "\n", 1)))
		return;
}