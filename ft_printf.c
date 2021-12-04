/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:34:34 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/04 18:30:47 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int len)
{
	if (!c)
		return (++len);
	write(1, &c, 1);
	return (++len);
}

int	ft_putstr(char *str, int len)
{
	int	i;
	if (!str)
		return (len);
	i = 0;
	while (str[i] != '\0')
		len = ft_putchar(str[i++], len);
	return (len);
}

int	ft_putnbr(int n, int len)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len = ft_putchar('-', len);
	}
	if (nbr < 10)
		len = ft_putchar(nbr + '0', len);
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	return (len);
}

int	ft_putnbr_base(int nbr, char *base, int len)
{
	long int	nb;

	nb = nbr;
	if (nb < 0)
	{
		len =ft_putchar('-', len);
		nb = nb * -1;
	}
	if (nb < 16)
	{
		len = ft_putchar(base[nb], len);
	}
	else
	{
		ft_putnbr_base(nb / 16, base, len);
		ft_putnbr_base(nb % 16, base, len);
	}
	return (len);
}

int is_type(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
			|| str[i + 1] == 'p' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == '%'))
	{
		return (1);
	}
	return (0);
}

/*
int	lenargs(const char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_type(&str[i]) == 1)
		{
			num++;
			i++;
		}
		else
			i++;
	}
	return (num);
}*/

int	put_type(char c, va_list args, int len)
{
	if (c == 'c')
		len = ft_putchar(va_arg(args, int), len);
	if (c == 's')
		len = ft_putstr(va_arg(args, char*), len);
	if (c == 'p')
		len = ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", len);
	if (c == 'd')
		len = ft_putnbr(va_arg(args, int), len);
	if (c == 'i')
		len = ft_putnbr(va_arg(args, int), len);
	if (c == 'u')
		len = ft_putnbr(va_arg(args, unsigned int), len);
	if (c == 'x')
		len = ft_putnbr_base(va_arg(args, int), "0123456789abcdef", len);
	if (c == 'X')
		len = ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", len);
	if (c == '%')
		len = ft_putchar('%', len);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	i_str;
	int	len;
	va_list	args;

	va_start(args, str);
        i_str = 0;
	len = 0;
	while (str[i_str] != '\0')
	{
		if (is_type(&str[i_str]) == 0)
                {
			len = ft_putchar(str[i_str], len);
		}
		else
		{
			len = put_type(str[i_str + 1], args, len);
			i_str++;
		}
		i_str++;
	}
	va_end(args);
	return (len);
}
