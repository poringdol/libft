#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int i;
	char *copy;

	i = 0;
	while (str[i])
		i++;
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
