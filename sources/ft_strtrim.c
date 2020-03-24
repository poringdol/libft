#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		begin;
	int		end;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	begin = 0;
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	end = i - 1;
	if (begin < end)
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
	if (!(str = ft_strnew(end - begin + 1)))
		return (NULL);
	i = 0;
	while (begin <= end)
		str[i++] = s[begin++];
	return (str);
}