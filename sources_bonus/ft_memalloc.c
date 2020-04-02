#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	int	i;
	char	*ptr;

	ptr = malloc(size * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = size - 1;
	while (i >= 0)
	{
		ptr[i] = 0;
		i--;
	}
	return (ptr);
}
