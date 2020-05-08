/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:49:27 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:05:37 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		if (write(fd, &s[i], 1))
			i++;
	}
}
