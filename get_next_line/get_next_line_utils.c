/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:16 by dbaule            #+#    #+#             */
/*   Updated: 2022/12/08 13:42:50 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	x;

	x = 0;
	while (string[x])
		x++;
	return (x);
}

char	*ft_strchr(char *a)
{
	size_t	x;
	size_t	y;
	char	*tmp;

	x = 0;
	y = 0;
	while (a[x] && a[x] != '\n')
		x++;
	if (!a[x])
	{
		free (a);
		return (NULL);
	}
	tmp = ft_calloc((sizeof(char)), (ft_strlen(a) - x + 1));
	x++;
	while (a[x])
	{
		tmp[y] = a[x];
		y++;
		x++;
	}
	free (a);
	return (tmp);
}

char	*ft_strdup(const char *src)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = ft_calloc(sizeof(char), ft_strlen(src) + 1);
	if (!tab)
		return (NULL);
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	tab = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	while (s1[x])
	{
		tab[x] = s1[x];
		x++;
	}
	while (s2[y])
		tab[x++] = s2[y++];
	tab[x] = '\0';
	return (tab);
}
