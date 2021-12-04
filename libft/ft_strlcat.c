/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:27:33 by xle-baux          #+#    #+#             */
/*   Updated: 2021/11/30 09:51:41 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (i >= dstsize)
		return (dstsize + src_len);
	while ((i < dstsize - 1) && (src[j] != '\0'))
	{
		if (src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
		}
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
