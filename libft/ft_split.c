/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:43:14 by xle-baux          #+#    #+#             */
/*   Updated: 2021/12/01 13:57:24 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_lines(char const *s, char c)
{
	size_t	i;
	size_t	lines;

	i = 0;
	lines = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			lines++;
		i++;
	}
	return (lines);
}

static int	count_chars(char const *s, char c)
{
	int	i;
	int	chars;

	i = 0;
	chars = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		chars++;
	}
	return (chars);
}

static char	**ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	**check(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_lines(s, c) + 1));
	if (split == 0)
		return (NULL);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	y;
	size_t	x;

	split = check(s, c);
	if (split == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (i < ft_strlen(s) && y < count_lines(s, c))
	{
		while (s[i] == c)
			i++;
		x = 0;
		split[y] = malloc(sizeof(char) * (count_chars(&s[i], c) + 1));
		if (split[y] == 0)
			return (ft_freetab(split));
		while (s[i] != c && s[i] != '\0')
			split[y][x++] = s[i++];
		split[y++][x] = '\0';
		i++;
	}
	split[count_lines(s, c)] = 0;
	return (split);
}
