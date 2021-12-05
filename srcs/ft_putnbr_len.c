/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:41:31 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/05 17:00:01 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_len(int n, int len)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len = ft_putchar_len('-', len);
	}
	if (nbr < 10)
		ft_putchar_len(nbr + '0', len);
	else if (nbr >= 10)
	{
		len = ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
	return (len + 1);
}
