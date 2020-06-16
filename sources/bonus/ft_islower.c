/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:42:10 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:42:11 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islower(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch);
	return (0);
}
