/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:56:40 by xle-baux          #+#    #+#             */
/*   Updated: 2021/11/30 12:50:29 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*buffer_dest;
	const char	*buffer_src;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	buffer_dest = dest;
	buffer_src = src;
	if (buffer_dest > buffer_src)
		while (n-- > 0)
			buffer_dest[n] = buffer_src[n];
	else
	{
		while (i < n)
		{
			buffer_dest[i] = buffer_src[i];
			i++;
		}
	}
	return (dest);
}
