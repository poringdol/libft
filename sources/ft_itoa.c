#include "libft.h"

static int count_len(int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	int				len;
	char*			str;
	unsigned int	n_tmp;

	i = n;
	len = count_len(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n_tmp = -n;
	}
	else
		n_tmp = n;
	i = len - 1;
	if (n == 0)
		str[0] = '0';
	while (n_tmp != 0)
	{
		str[i--] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	return (str);
}