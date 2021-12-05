/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:34:34 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/05 18:25:56 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

int	put_type(char c, va_list args, int len)
{
	if (c == 'c')
		len = ft_putchar_len(va_arg(args, int), len);
	if (c == 's')
		len = ft_putstr_len(va_arg(args, char*), len);
	if (c == 'p')
		len = ft_putptr_len(va_arg(args, unsigned long long int), len);
	if (c == 'd')
		len = ft_putnbr_len(va_arg(args, int), len);
	if (c == 'i')
		len = ft_putnbr_len(va_arg(args, int), len);
	if (c == 'u')
		len = ft_put_unint_nbr_len(va_arg(args, unsigned int), len);
	if (c == 'x')
		len = ft_put_lower_hexa(va_arg(args, long int), len);
	if (c == 'X')
		len = ft_put_upper_hexa(va_arg(args, long int), len);
	if (c == '%')
		len = ft_putchar_len('%', len);
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
			len = ft_putchar_len(str[i_str], len);
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
