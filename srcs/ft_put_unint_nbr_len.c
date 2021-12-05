/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unint_nbr_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:25:13 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/05 17:58:05 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_unint_nbr_len(int n, int len)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr < 10)
		ft_putchar_len(nbr + '0', len);
	else if (nbr >= 10)
	{
		len = ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
	return (len + 1);
}
