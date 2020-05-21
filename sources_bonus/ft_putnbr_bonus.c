/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:31:20 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:31:36 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

int	ft_putnbr(int n)
{
	long long	i;
	int			tmp;
	int			len;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n < 0)
		write(1, "-", 1);
	len = n >= 0 ? 0 : 1;
	tmp = n > 0 ? n : -n;
	i = 1;
	while (i <= tmp)
		i *= 10;
	if (tmp != 0)
		i /= 10;
	while (i > 0)
	{
		ft_putchar(tmp / i + '0');
		tmp %= i;
		i /= 10;
		len++;
	}
	ft_putchar('\n');
	return (len);
}
