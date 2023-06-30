/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:29:47 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 14:41:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		nbrwords(char const *s, char c);
static char		**ft_lines(char const *s, char c, char **strs, int x);
static char		*ft_dupstr(char const *s, int i, int j);

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (nbrwords(s, c) + 1));
	if (!strs)
		return (NULL);
	strs = ft_lines(s, c, strs, 0);
	if (strs)
		strs[nbrwords(s, c)] = 0;
	return (strs);
}

static int	nbrwords(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\n'))
			i++;
		if (s[i] != c && s[i] != 0 && s[i] != '\n')
		{
			words++;
			i++;
		}
		while (s[i] && (s[i] != c))
			i++;
	}
	return (words);
}

static	char	**ft_lines(char const *s, char c, char **strs, int x)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\n'))
			i++;
		j = i;
		while (s[j] && s[j] != c && s[j] != '\n')
			j++;
		if (s[j] == c || s[j] == '\n'
			|| (!s[j] && s[j - 1] != c && s[j - 1] != '\n'))
		{
			strs[x] = ft_dupstr(s, i, j);
			if (strs[x] == NULL)
				return (ft_free_double_char(strs), NULL);
			x++;
			i = j;
		}
	}
	return (strs);
}

static char	*ft_dupstr(char const *s, int i, int j)
{
	char	*dup;
	int		x;

	dup = malloc(sizeof(char) * (j - i + 1));
	if (!dup)
		return (perror("error"), NULL);
	x = 0;
	while (s[i] && i < j)
	{
		dup[x] = s[i];
		x++;
		i++;
	}
	dup[x] = 0;
	return (dup);
}
