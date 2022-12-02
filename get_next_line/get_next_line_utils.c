/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:16 by dbaule            #+#    #+#             */
/*   Updated: 2022/12/02 21:59:29 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	x;

	x = 0;
	while (string[x] != 0)
		x++;
	return (x);
}

char	*ft_strchr(const char *a, int c)
{
	size_t			x;
	unsigned char	cha;
	
	x = 0;
	cha = (char)c;
//	printf("str dans strchr === %s\n ", a);
	while (a[x])
	{
		if (a[x] == cha)
			return ((char *)a + (x + 1));
		x++;
	}
	if (cha == 0)
		return ((char *) a + x);
	return (NULL);
}

char	*ft_dup(const char *src, char *tab)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_strdup(const char *src)
{
	char	*tab;

	tab = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!tab)
		return (NULL);
	ft_dup(src, tab);
	return (tab);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	unsigned char	*tab;
	size_t			x;
	size_t			n;

	x = 0;
	if (elementSize && elementCount > SIZE_MAX / elementSize)
		return (0);
	n = elementCount * elementSize;
	tab = malloc(elementCount * elementSize);
	if (!tab)
		return (NULL);
	if (n != 0)
	{
		while (x < n)
		{
			((char *)tab)[x] = '\0';
			x++;
		}
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*tab;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	tab = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (!tab)
		return (NULL);
	while (s1[x])
	{
		tab[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		tab[x] = s2[y];
		x++;
		y++;
	}
	tab[x] = '\0';
	free (s1);
	return (tab);
}
