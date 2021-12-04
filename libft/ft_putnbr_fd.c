/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:28:05 by xle-baux          #+#    #+#             */
/*   Updated: 2021/11/29 15:48:06 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (fd != -1)
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar_fd('-', fd);
		}
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', fd);
		else if (nbr >= 10)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
	}
}
