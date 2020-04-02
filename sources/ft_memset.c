#include <string.h>

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *ptr = (unsigned char *)destination;
	while (n > 0)
	{
		n--;
		ptr[n] = c;
	}
	return (destination);
}
