/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 11:49:10 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:11:15 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		if (write(fd, s, 1))
			s++;
	}
	if (!(write(fd, "\n", 1)))
		return ;
}
