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

void	ft_putnbr(int n)
{
	long long	i;
	int			tmp;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
		write(1, "-", 1);
	tmp = n > 0 ? n : -n;
	i = 1;
	while (i * 10 < tmp)
		i *= 10;
	while (i > 0)
	{
		ft_putchar(tmp / i + '0');
		tmp %= i;
		i /= 10;
	}
}
