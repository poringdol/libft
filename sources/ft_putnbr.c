#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;
	unsigned int tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = n * -1;
		write(1, "-", 1);
	}
	i = 1;
	if (tmp >= 1000000000)
	{
		i = 1000000000;
		n = 1;
	}
	while (i <= tmp && n != 1)
		i = i * 10;
	if (n != 1 && tmp != 0)
		i = i / 10;
	while (i > 0)
	{
		ft_putchar(tmp / i + '0');
		tmp = tmp % i;
		i = i / 10;
	}
}