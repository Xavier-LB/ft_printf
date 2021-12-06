/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:04:14 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/06 11:28:03 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_hexa(unsigned long long int nb, int len)
{
	char			*hexa;

	hexa = "0123456789abcdef";
	if (nb < 16)
	{
		ft_putchar_len(hexa[nb], len);
	}
	else
	{
		len = ft_put_hexa(nb / 16, len);
		ft_put_hexa(nb % 16, len);
	}
	return (len + 1);
}

int	ft_putptr_len(unsigned long long int nb, int len)
{
	char			*hexa;

	hexa = "0123456789abcdef";
	ft_putstr_len("0x", len);
	len = len + 2;
	if (nb < 16)
	{
		ft_putchar_len(hexa[nb], len);
	}
	else
	{
		len = ft_put_hexa(nb / 16, len);
		ft_put_hexa(nb % 16, len);
	}
	return (len + 1);
}
