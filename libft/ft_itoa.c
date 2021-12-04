/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:24:41 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/01 09:38:07 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static long int	ft_power(long int n, long int p)
{
	long int	buff;

	buff = n;
	if (n == 0)
		return (1);
	while (p > 1)
	{
		n = n * buff;
		p--;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	last_digit;
	long int	long_n;
	char		*str;

	i = 0;
	long_n = n;
	str = (char *)malloc(sizeof(char) * (len_n(n) + 1));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		str[i++] = '-';
		long_n = (long_n * -1);
		last_digit = ft_power(10, (len_n(n) - 1));
	}
	else
		last_digit = ft_power(10, len_n(n));
	while (i < len_n(n))
	{
		str[i++] = ((long_n % last_digit) / (last_digit / 10) + '0');
		last_digit = last_digit / 10;
	}
	str[i] = '\0';
	return (str);
}
