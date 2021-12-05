/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_upper_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:17:03 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/05 16:48:11 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_upper_hexa(int nb, int len)
{
	char			*hexa;
	unsigned int	n;

	hexa = "0123456789ABCDEF";
	n = nb;
	if (n < 16)
	{
		ft_putchar_len(hexa[n], len);
	}
	else
	{
		len = ft_put_upper_hexa(n / 16, len);
		ft_put_upper_hexa(n % 16, len);
	}
	return (len + 1);
}
