/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:26:13 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/02 14:28:29 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

static int	is_zero(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (is_charset(s1[i], set) == 0)
		i++;
	if (s1[i] == '\0')
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;
	int		i;

	if (!s1)
		return (NULL);
	if (is_zero(s1, set) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (is_charset(s1[start], set) == 0)
		start++;
	while (is_charset(s1[end - 1], set) == 0)
		end--;
	trim = malloc(sizeof(char) * ((end - start) + 1));
	if (trim == 0)
		return (0);
	i = 0;
	while (i <= (end - (start - i)))
		trim[i++] = s1[start++];
	trim[end - (start - i)] = '\0';
	return (trim);
}
