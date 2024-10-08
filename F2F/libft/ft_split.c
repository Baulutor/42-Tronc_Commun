/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:29:47 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 18:40:10 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	nbrwords(char const *s, char c)
{
	size_t	count;
	size_t	x;

	x = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[x] && s[x] != c)
	{
		x++;
		count++;
	}
	while (s[x])
	{
		if (s[x] == c && s[x + 1] != c && s[x + 1])
			count++;
		x++;
	}
	return (count);
}

char	**ft_freetab(char **tab)
{
	size_t	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
	return (0);
}

static char	**ft_splitdub(char **tab, const char *s, char c, size_t x)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = x;
	if (c == 0)
	{
		tab[0] = ft_strdup(s);
		tab[1] = 0;
		return (tab);
	}
	while (x <= ft_strlen(s))
	{
		if ((s[x] && s[x] == c) || s[x] == 0)
		{
			tab[count++] = ft_substr(s, index, x - index);
			if (!tab[count - 1])
				return (ft_freetab(tab), perror("Error"), NULL);
			index = x;
			while (s[x] == c)
			{
				if (s[x + 1] && s[x + 1] == '\n')
					return (tab);
				index++;
				if (s[x + 1])
					x++;
			}
		}
		x++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	x;

	x = 0;
	if (!s)
		return (perror("str"),NULL);
	tab = malloc(sizeof(char *) * (nbrwords(s, c) + 1));
	if (!tab)
		return (perror("Error"), NULL);
	if (s[x] == 0)
	{
		tab[0] = 0;
		return (tab);
	}
	tab[nbrwords(s, c)] = 0;
	while (s[x] == c)
		x++;
	if (s[x] == 0)
	{
		tab[0] = 0;
		return (tab);
	}
	if (ft_splitdub(tab, s, c, x) == NULL)
		return (NULL);
	return (tab);
}
