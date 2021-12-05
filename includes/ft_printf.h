/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:14:54 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/05 18:25:34 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_len(char c, int len);
int	ft_putstr_len(char *str, int len);
int	ft_putnbr_len(int n, int len);
int	ft_put_lower_hexa(int nb, int len);
int	ft_put_upper_hexa(int nb, int len);
int	ft_put_unint_nbr_len(int n, int len);
int	ft_putptr_len(unsigned long long int nb, int len);

# endif
