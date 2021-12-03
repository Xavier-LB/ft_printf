/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:34:34 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/03 15:11:27 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	lenargs(const char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'p' || str[i + 1] == 'd'
				|| str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == 'x' || str[i + 1] == '%'))
		{
			num++;
			i++;
		}
		else
			i++;
	}
	return (num);
}

int	ft_printf(const char *str, ...)
{
	int	num_args;
	va_list	args;

	num_args = lenargs(str);
	va_start(args, str);
	while ()
	{
		
	}
	va_end(num_args);
	return (0);
}
