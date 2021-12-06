/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:44:22 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/06 11:35:29 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_len(char *str, int len)
{
	int		i;
	char	null[6];

	i = 0;
	null = "(null)";
	if (!str)
	{
		while (null[i] != '\0')
		{
			len = ft_putchar_len(null[i++], len);
		}
		return (len);
	}
	while (str[i] != '\0')
		len = ft_putchar_len(str[i++], len);
	return (len);
}
