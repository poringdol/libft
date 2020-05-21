/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:49:19 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:08:42 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	i;
	int			tmp;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	tmp = n > 0 ? n : -n;
	i = 1;
	while (i <= tmp)
		i *= 10;
	if (tmp != 0)
		i /= 10;
	while (i > 0)
	{
		ft_putchar_fd(tmp / i + '0', fd);
		tmp %= i;
		i /= 10;
	}
}
