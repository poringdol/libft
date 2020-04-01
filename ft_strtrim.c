#include <string.h>
#include "libft.h"

static int	ft_begin(char const *s1, char const *set)
{
	int		begin;
	size_t	j;

	begin = 0;
	j = 0;
	while (set[j])
	{
		if (s1[begin] == set[j])
		{
			begin++;
			j = 0;
		}
		else
			j++;
	}
	return (begin);
}

static int	ft_end(char const *s1, char const *set, int end)
{
	size_t j;

	j = 0;
	while (set[j])
	{
		if (s1[end] == set[j])
		{
			end--;
			j = 0;
		}
		else
			j++;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int	begin;
	int	end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	begin = ft_begin(s1, set);

	end = i - 1;
	if (begin < end)
		end = ft_end(s1, set, end);
	if (!(str = ft_calloc((end - begin + 2), sizeof(char))))
		return (NULL);
	i = 0;
	while (begin <= end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}
