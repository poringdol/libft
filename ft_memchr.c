#include <string.h>

void	*ft_memchr(const void *arr, int ch, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*buf;

	i = 0;
	buf = (char *)arr;
	while (i < n)
	{
		if (buf[i] == (char)ch)
		{
			ptr = &buf[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
